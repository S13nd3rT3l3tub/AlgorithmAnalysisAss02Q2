#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Based on https://www.geeksforgeeks.org/0-1-knapsack-problem-to-print-all-possible-solutions/

struct CompareMemberWeightValue {
	bool operator()(const std::pair<int, int>& _a, const std::pair<int, int>& _b) const {
		return _a.second < _b.second;
	}
};

int PermutateThroughKnapSack(std::vector<int> _values,std::vector<int> _weights, int _maxCapacity) {
	// Unequal number of values given; Unable to run algorithm
	if (_values.size() != _weights.size())
		return 0;

	// Map to store weights with profits of each item
	//std::map<int, std::pair<int, int>> uMap;
	std::vector<std::pair<int, int>> itemList{}, possibleList{};

	// Create pair containing value and weight of item and insert into container
	//for (int i{ 0 }; i < _values.size(); ++i)
	//	uMap.emplace(i, std::pair<int, int>{_values[i], _weights[i]});
	for (int i{ 0 }; i < _values.size(); ++i)
		itemList.emplace_back(std::pair<int, int>{_values[i], _weights[i]});

	// Variables for permutation looping
	//std::set<std::vector<std::pair<int, int>>> set_sol;
	int result = INT_MIN;
	int remaining_weight;
	int sum = 0;

	do {
		// Set initial values
		sum = 0;
		remaining_weight = _maxCapacity;
		possibleList.clear();



	} while (std::next_permutation(itemList.begin(), itemList.end(), CompareMemberWeightValue()));

	return result;
}

int main()
{
	std::vector<int>	values	{ 1, 4, 8, 5 },
						weights{ 3, 3, 5, 6 };
	int capacity{ 7 };
	
	int maximum = PermutateThroughKnapSack(values, weights, capacity);
	std::cout << "Maximum Profit = ";
	std::cout << maximum;
	
	return 0;
}