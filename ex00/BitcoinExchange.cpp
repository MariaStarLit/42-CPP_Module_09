#include "BitcoinExchange.hpp"

//Constructores
BitcoinExchange::BitcoinExchange()
{
	extractDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::Data::Data(const std::string &d, float v) : date(d), value(v)
{}

//Destructor
BitcoinExchange::~BitcoinExchange()
{}

//Operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if ( this != &copy )
	{
		this->my_data = copy.my_data;
	}
	return *this;
}

//Member functions
void	BitcoinExchange::checkFile(const std::string &file_name)
{
	(void)file_name;
}

void	BitcoinExchange::extractDatabase(void)
{
	std::string line;
	std::string header;
	bool error_parcing = false;
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cout << RED << "Error: could not open file 'data.csv'." << RESET << std::endl;
		return;
	}

	std::getline(file, line);
	std::istringstream aux(line);
	aux >> header;
	if (header != "date,exchange_rate")
	{
		std::cout << RED << "Error: bad input => " << header << RESET << std::endl;
	}
	int i = 0;
	while(std::getline(file, line) && i < 10)
	{
		Data valid = parcingDatabaseLine(line, error_parcing);
		//std::cout << line << std::endl;
		i++;
	}
	file.close();
}

std::string trim(const std::string &str)
{
	std::size_t first = str.find_first_not_of(" \t\r\f\v");
	if (first == std::string::npos)
	{
		return "";
	}

	std::size_t last = str.find_last_not_of(" \t\r\f\v");

	return (str.substr(first, last - first + 1));
}

float BitcoinExchange::validValue(const std::string &val)
{
	//std::cout << "val: |" << val << "|" << std::endl;
	int i = 0;
	if (val.empty())
	{
		std::cout << RED << "Error: missing a number." << RESET << std::endl;
		return (-1);
	}
	if (val[i] == '-' || val[i] == '+')
		i++;
	while(val[i])
	{
		if (!std::isdigit(val[i]))
		{
			std::cout << RED << "Error: not a number." << RESET << std::endl;
			return (-1);
		}
		i++;
	}
	int value = std::atof(val.c_str());
	if (value < 0.0)
	{
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return (-1);
	}
	if (value > 1000.0)
	{
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
		return (-1);
	}
	return (value);
}

bool BitcoinExchange::validDate(const std::string &date) const
{
	
	if (date.length() != 10)
		return (false);
	for(int i = 0; date[i]; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 6).c_str());
	int day = std::atoi(date.substr(8, 9).c_str());
	int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	//std::cout << year << " - " << month << " - " << day << std::endl;

	if (year < 2009 || month < 1 || month > 12)
		return false;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		days_of_month[1] = 29;
	if (day < 1 || day > days_of_month[month - 1])
		return false;
	return true;
}

BitcoinExchange::Data	BitcoinExchange::parcingLine(const std::string &raw_line, bool &error, char seperator)
{
	error = false;
	std::istringstream file_l(raw_line);

	std::string date, line, aux_v;
	float value = -1;
	if (!std::getline(file_l, line, seperator))
	{
		std::cout << RED << "Error: bad line format." << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	date = trim(line);
	if (!validDate(date))
	{
		std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	if (!std::getline(file_l, line, seperator))
	{
		std::cout << RED << "Error: bad line format." << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	aux_v = trim(line);
	value = validValue(aux_v);
	//std::cout << value << std::endl;
	if (value == -1) 
	{
		error = true;
		return (Data("", 0));
	}
	
	return (Data(date, value));
}

BitcoinExchange::Data	BitcoinExchange::parcingInputLine(const std::string &line, bool &error)
{
	return parcingLine(line, error, '|');
}

BitcoinExchange::Data	BitcoinExchange::parcingDatabaseLine(const std::string &line, bool &error)
{
	return parcingLine(line, error, ',');
}
