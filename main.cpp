# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <climits>
# include <ctime>

class PmergeMe
{
	private:
		PmergeMe();									//Default Constructor
		PmergeMe(const PmergeMe &copy);				//Copy Constructor
		PmergeMe &operator=(const PmergeMe &copy);	//Copy Operator

		bool	odd_nbr;
		int		straggler;
		static const int jacobsthal[35];

		std::vector<int>inputVec;
		std::vector<int>aVec;
		std::vector<int>bVec;

		std::list<int>inputList;
		std::list<int>aList;
		std::list<int>bList;

	public:
		PmergeMe(std::vector<int> _aux);			//Constructor
		~PmergeMe();								//Destructor

		//Member Functions
		void	makePairList(void);
		void	sortList(void);
		
		void	makePairVector(void);
		bool	isAVectorSorted(void);
		bool	isSorted(void);
		void	sortPairVector(void);
		void	insert_vector(void);
		void	sortVector(void);
};

//Constructores
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(std::vector<int> aux)
{
	this->odd_nbr = false;
	std::vector<int>::iterator it = aux.begin();
	std::vector<int>::iterator itend = aux.end();
	while (it < itend)
	{
		int n = *it;
		this->inputVec.push_back(n);
		this->inputList.push_back(n);
		it++;
	}
}

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
void	PmergeMe::makePairList(void)
{}

void	PmergeMe::sortList(void)
{}

//Vector
void	PmergeMe::makePairVector(void)
{
	if (this->inputVec.size() % 2 != 0)
	{
		this->odd_nbr = true;
		this->straggler = this->inputVec.back();
		this->inputVec.pop_back();
	}

	std::vector<int>::iterator	it;
	for(it = inputVec.begin(); it != inputVec.end(); it += 2)
	{
		if ((it + 1) == inputVec.end())
			break;
		
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		aVec.push_back(*it);
		bVec.push_back(*(it + 1));
	}
}

bool	PmergeMe::isAVectorSorted(void)
{
	std::vector<int>::iterator iter;
	for (iter = aVec.begin(); iter != aVec.end(); ++iter)
	{
		if ((iter + 1) == aVec.end())
				break;
		if (*iter < *(iter + 1))
			return (false);
	}
	return (true);
}

bool	PmergeMe::isSorted(void)
{
	std::vector<int>::iterator iter;
	for (iter = aVec.begin(); iter != aVec.end(); ++iter)
	{
		if ((iter + 1) == aVec.end())
				break;
		if (*iter > *(iter + 1))
		{
			std::cout << RED << "False" << RESET << std::endl;
			return (false);
		}
	}
	std::cout << GREEN << "True!" << RESET << std::endl;
	return (true);
}


void	PmergeMe::sortPairVector(void)
{
	// std::cout << GREEN << "a: ";
	// std::vector<int>::iterator iter;
	// for (iter = aVec.begin(); iter != aVec.end(); ++iter)
	// {
	// 	std::cout << *iter << " ";
	// }
	// std::cout << std::endl << CYAN << "b: ";
	// for (iter = bVec.begin(); iter != bVec.end(); ++iter)
	// {
	// 	std::cout << *iter << " ";
	// }
	// std::cout << RESET << std::endl;
	std::vector<int>::iterator a_it;
	std::vector<int>::iterator b_it;
	while (!isAVectorSorted())
	{
		a_it = aVec.begin();
		b_it = bVec.begin();
		while((a_it != aVec.end()) || (b_it != bVec.end()))
		{
			if ((a_it + 1) == aVec.end())
				break;
			if (*a_it < *(a_it + 1))
			{
				std::iter_swap(a_it, a_it + 1);
				std::iter_swap(b_it, b_it + 1);
			}
			a_it++;
			b_it++;
		}
	}
}

const int PmergeMe::jacobsthal[35] =
{
	-1, 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765
};

void	PmergeMe::insert_vector()
{
	int jal_index = 0;
	while (jacobsthal[jal_index] < (int)bVec.size())
	{
		++jal_index;
		int position = (jacobsthal[jal_index] < (int)bVec.size()) ? jacobsthal[jal_index] : bVec.size() - 1;
		while (jacobsthal[jal_index - 1] < position)
		{
			std::vector<int>::iterator bVec_it = bVec.begin() + position;
			if (bVec_it != bVec.end())
				aVec.insert(std::upper_bound(aVec.begin(), aVec.end(), *bVec_it), *bVec_it);
			position--;
		}
	}
	if (odd_nbr == true)
	{
		std::vector<int>::iterator insertionPos;
		odd_nbr = false;
		insertionPos = std::upper_bound(aVec.begin(), aVec.end(),
			straggler);
		aVec.insert(insertionPos, straggler);
	}
}

void	PmergeMe::sortVector(void)
{
	std::vector<int>::iterator	it;
	std::clock_t				vec_start, vec_end;
	double						vec_time;

	std::cout << "Before: ";
	for(it = this->inputVec.begin(); it != this->inputVec.end(); it++)
		std::cout << *it << " ";
	std::cout<<std::endl;
	
	vec_start = std::clock();
	makePairVector();
	sortPairVector();
	insert_vector();
	vec_end = std::clock();
	vec_time = static_cast<double>(vec_end - vec_start) / CLOCKS_PER_SEC;

	std::cout << "After:  ";
	for(it = this->aVec.begin(); it != this->aVec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->inputVec.size() 
	<< " elements with std::verctor : " << std::fixed << vec_time << "us" << std::endl;
}

bool validInput(const std::string &str, std::vector<int> &aux)
{
	long int nbr;
	std::vector<int>::iterator it = aux.begin();
	std::vector<int>::iterator ite = aux.end();
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << RED << "Error! Not a valid input or negative number: " << str << RESET << std::endl;
			return (false);
		}
	}
	nbr = atol(str.c_str());
	if (nbr > INT_MAX)
	{
		std::cout << RED << "Error! Number overflow: " << nbr << RESET << std::endl;
		return (false);
	}
	if (find(it, ite, nbr) != ite)
	{
		std::cout << RED << "Error! Forbiden duplicated number found: " << nbr << RESET << std::endl;
		return (false);
	}
	aux.push_back(nbr);
	return (true);
}

int main(int argc, char **argv)
{
	std::vector<int> v_aux;
	(void)argv;
	(void)argc;

	v_aux.push_back(5);
	v_aux.push_back(2);
	v_aux.push_back(3);
	v_aux.push_back(1);
	v_aux.push_back(4);
	v_aux.push_back(7);
	v_aux.push_back(6);
	PmergeMe sort(v_aux);
	sort.sortVector();

	sort.isSorted();
	return (0);
}