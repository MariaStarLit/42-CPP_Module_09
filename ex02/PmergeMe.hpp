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
		PmergeMe &operator=(const PmergeMe &copy);	//Operator
		~PmergeMe();								//Destructor
		
		//Member Functions
		static void mergeInsertList(std::list<int> &list, std::list<int> &insert);
		static void mergeInsertVector(std::vector<int> &vector, std::vector<int> &insert);

	public:
		static void	sortList(std::list<int> &list);
		static void	printList(std::list<int> &list);
		static void	sortVector(std::vector<int> &vector);
		static void	printVector(std::vector<int> &vector);
};
