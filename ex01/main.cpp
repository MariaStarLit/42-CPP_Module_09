#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << RED << "Error! Please input only of expression." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./RPN \"Exprecion\"" << RESET << std::endl;
		return (1);
	}

	return (0);
}