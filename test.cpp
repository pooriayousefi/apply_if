
#include "apply_if.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <stdexcept>

auto main()->int
{
	try
	{
		// apply test
		std::vector<int> data_1{ -1, 9, 0, 3, 4, 2, 2, 4, 5, -3, 0, -2 };
		std::cout << "\n\t";
		for (auto& e : data_1)
			std::cout << e << ' ';
		apply_if(data_1.begin(), data_1.end(), [](const int& val) { return val % 2 == 0; }, [](auto& val) { val *= 10; });
		std::cout << "\n\n\t";
		for (auto& e : data_1)
			std::cout << e << ' ';
		apply(data_1.begin(), data_1.end(), [](auto& val) { val *= 1000; });
		std::cout << "\n\n\t";
		for (auto& e : data_1)
			std::cout << e << ' ';
		std::cout << "\n\n\t";

		return EXIT_SUCCESS;
	}
	catch (const std::exception & xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}
