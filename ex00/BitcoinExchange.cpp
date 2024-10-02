#include "BitcoinExchange.hpp"

//Constructores
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
}

//Destructor
BitcoinExchange::~BitcoinExchange()
{
}


//Operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &operator<<( std::ostream & o, BitcoinExchange const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


//Member functions
