#include "RPN.hpp"

//Constructores
RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}


//Destructor
RPN::~RPN()
{}

//Opecator
RPN &RPN::operator=(const RPN &copy)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}
