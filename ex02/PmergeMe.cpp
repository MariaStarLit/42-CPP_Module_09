#include "PmergeMe.hpp"

//Constructores
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

//Destructor
PmergeMe::~PmergeMe()
{
}

//Operator
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

// std::ostream &operator<<( std::ostream & o, PmergeMe const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }
