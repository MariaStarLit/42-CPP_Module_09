#include "RPN.hpp"

std::stack<double> RPN::_exp;
double RPN::_res;

//Constructores
RPN::RPN()
{}

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
	(void)copy;
	return *this;
}

//Member Functions
void	RPN::calculate(std::string exp)
{
	std::stringstream skipspace(exp);
	std::string pile, op;
	op = "+-/*";
	while (skipspace >> pile)
	{
		//std::cout << "|" << pile << "|" << std::endl;
		if (atoi(pile.c_str()) < 0 || atoi(pile.c_str()) > 9)
		{
			std::cout << RED << "Error! Invalid number needs to be from 0 to 9." << RESET<< std::endl;
			return ;
		}
		if ((std::isdigit(pile[0])))
			_exp.push(pile[0] - 48);
		else if (op.find(pile[0]) != std::string::npos)
		{
			if (_exp.size() < 2)
			{
				std::cout << RED << "Error! Insufficient numbers." << RESET<< std::endl;
				return ;
			}
			try 
			{
				executeOperation(pile[0]);
			}
			catch (std::exception &e)
			{
				std::cout << RED << e.what() << RESET << std::endl;
				return;
			}
		}
		else
		{
			std::cout << RED << "Error! Invalid input." << RESET<< std::endl;
			return ;
		}
	}
	if (_exp.size() != 1)
		std::cout << RED << "Error! Too many numbers." << RESET << std::endl;
	else
		std::cout << _res << std::endl;
}


void RPN::executeOperation(char op)
{
	double tmp = _exp.top();
	_exp.pop();
	switch (op)
	{
		case '+':
			_res = _exp.top() + tmp;
			break ;
		case '-':
			_res = _exp.top() - tmp;
			break ;
		case '/':
			if (tmp == 0)
				throw std::runtime_error("Cant't divide by zero");
			_res = _exp.top() / tmp;
			break ;
		case '*':
			_res = _exp.top() * tmp;
			break ;
	}
	_exp.pop();
	_exp.push(_res);
}