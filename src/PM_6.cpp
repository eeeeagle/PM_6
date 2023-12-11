#include "Search.hpp"
#include <random>

bool is_value(const std::string& str)
{
	for (auto it : str)
		if (!isdigit(it))
			return false;
	return !str.empty();
}

int get_value(const std::string& text)
{
	while (true)
	{
		std::cout << text;
		std::string input_string;
		getline(std::cin, input_string);

		if (is_value(input_string))
			return std::stoi(input_string);
		else
			std::cout << "Incorrect input. Try again." << std::endl << std::endl;
	}
}

std::vector<int> random_int_vector(const size_t size)
{
	std::vector<int> vector = {};
	for (int i = 0; i < size; vector.push_back(i++));
	std::random_device rd;
	std::mt19937 mt(rd());
	std::shuffle(vector.begin(), vector.end(), mt);
	return vector;
}

int main()
{
	const int size = get_value("Enter vector size: ");
	std::cout << std::endl;

	const int value = get_value("Find value: ");
	std::cout << std::endl;

	const std::vector vector = random_int_vector(size);
	std::vector<SearchStats> stats;

	std::vector vector_copy = vector;
	stats.push_back(search(vector_copy, value, consistent_search, "Regular"));

	vector_copy = vector;
	stats.push_back(search(vector_copy, value, consistent_fast_search, "Fast"));

	vector_copy = vector;
	stats.push_back(search(vector_copy, value, consistent_fastest_search, "Fastest"));

	std::cout << std::setw(10) << "TYPE" << std::right << " | TIME (ms)" << std::endl
		<< "-----------|-----------" << std::endl;
	for (auto& it : stats)
		std::cout << std::setw(10) << it.get_name() << std::right << " | " << it.get_total_time() / 1000 << std::endl;
	std::cout << std::endl;
	
	return 0;
}
