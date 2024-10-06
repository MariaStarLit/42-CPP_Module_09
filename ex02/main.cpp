#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << RED << "Error! Please use an expression." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./PmergeMe 3 5 9 7 4" << RESET << std::endl;
		return (1);
	}
	(void)argv;
	return (0);
}