#pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <string>
# include <map>
# include <cstring>
# include <cstdlib>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	my_data;

	public:
		BitcoinExchange();											//Default Constructor
		BitcoinExchange(const BitcoinExchange &copy);				//Copy Constructor
		BitcoinExchange &operator=(const BitcoinExchange &copy);	//Copy Assiment Operator
		~BitcoinExchange();											//Destructor

		//Member Functions
		void	checkFile(const std::string &file_name);
		void	extractDatabase(void);
		bool	validDate(const std::string &date) const;
		float	validValue(const std::string &val);

		//Struct
		struct Data
		{
			Data(const std::string &d, float v);
			const std::string date;
			float value;
		};

		Data	parcingLine(const std::string &line, bool &error, char seperator);
		Data	parcingInputLine(const std::string &line, bool &error);
		Data	parcingDatabaseLine(const std::string &line, bool &error);
};
