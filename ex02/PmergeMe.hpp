# pragma once

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
		std::vector<int>_posVec;
		std::vector<int>aVec;
		std::vector<int>bVec;
		std::vector<int>_jacobVec;

		std::list<int>inputList;
		std::list<int>_posList;
		std::list<int>aList;
		std::list<int>bList;
		std::list<int>_jacobList;

	public:
		PmergeMe(std::vector<int> _aux);			//Constructor
		~PmergeMe();								//Destructor

		//Member Functions
		void	makePairList(void);
		void	sortList(void);
		
		void	makePairVector(void);
		bool	isAVectorSorted(void);
		void	sortPairVector(void);
		void	insert_vector(void);
		void	sortVector(void);
};
