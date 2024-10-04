#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << RED << "Error! Please input a file." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./btc file_name" << RESET << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange trade;

		//trade.checkfile(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Error! " << e.what() << RESET << std::endl;
		return (2);
	}
	return (0);
}