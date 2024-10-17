#include "PmergeMe.hpp"

//Constructores
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

//Operator
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	(void)copy;
	return *this;
}

//Destructor
PmergeMe::~PmergeMe()
{}

//List
void	PmergeMe::mergeInsertList(std::list<int> &list, std::list<int> &insert)
{
	(void)list;
	(void)insert;
}

void	PmergeMe::sortList(std::list<int> &list)
{
	(void)list;
}

void	PmergeMe::printList(std::list<int> &list)
{
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

//Vector
void	PmergeMe::mergeInsertVector(std::vector<int> &vector, std::vector<int> &insert)
{
	(void)vector;
	(void)insert;
}

void	PmergeMe::sortVector(std::vector<int> &vector)
{
	(void)vector;
}

void	PmergeMe::printVector(std::vector<int> &vector)
{
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator ite = vector.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
