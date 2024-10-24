# include "PmergeMe.hpp"

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
	if (argc < 2)
	{
		std::cout << RED << "Error! Please use an expression." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./PmergeMe 3 5 9 7 4" << RESET << std::endl;
		return (1);
	}
	else if (argc == 2)
	{
		std::istringstream aux(argv[1]);
		std::string input;
		while (aux >> input)
		{
			if (!validInput(input, v_aux))
				return (1);
		}
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			if (!validInput(argv[i], v_aux))
				return (1);
		}
	}

	PmergeMe sort(v_aux);
	sort.sortVector();
	sort.sortList();


	// std::clock_t vec_start, vec_end, list_start, list_end;
	// double vec_time, list_time;
	// int straggler;
	// bool odd_nbr = false;
	// std::vector<int> vec;
	// std::list<int>	list;

	// if (v_aux.size() % 2 != 0)
	// {
	// 	odd_nbr = true;
	// 	straggler = v_aux.back();
	// 	v_aux.pop_back();
	// }


	// std::cout << "Before: ";
	// PmergeMe::printVector(vec);
	

	// vec_start = std::clock();
	// PmergeMe::sortVector(vec);
	// if (odd_nbr)
	// 	std::upper_bound(vec.begin(), vec.end(), straggler);
	// vec_end = std::clock();
	// vec_time = static_cast<double>(vec_end - vec_start) / CLOCKS_PER_SEC;

	// list_start = std::clock();
	// PmergeMe::sortList(list);
	// if (odd_nbr)
	// {
	// 	std::cout << "Hey list" << std::endl;
	// 	std::list<int>::iterator add_straggler = std::upper_bound(list.begin(), list.end(), straggler);
	// 	list.insert(add_straggler, straggler);
	// }
	// list_end = std::clock();
	// list_time = static_cast<double>(list_end - list_start) / CLOCKS_PER_SEC;

	// std::cout << "After: ";
	// PmergeMe::printList(list);

	// std::cout << "Time to process a range of " << vec.size() << " elements with std::verctor : " << std::fixed << vec_time << "us" << std::endl;
	// std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << std::fixed << list_time << "us" << std::endl;

	return (0);
}