#pragma once

# include <iostream>
# include <string>

class BitcoinExchange
{
	private:
	
	public:
		BitcoinExchange();											//Default Constructor
		BitcoinExchange(const BitcoinExchange &copy);				//Copy Constructor
		~BitcoinExchange();											//Destructor

		BitcoinExchange &operator=(const BitcoinExchange &copy);	//Copy Assiment Operator
};

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i);
