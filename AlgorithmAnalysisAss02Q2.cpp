#include <iostream>
#include <vector>
#include <map>

// Based on https://www.geeksforgeeks.org/0-1-knapsack-problem-to-print-all-possible-solutions/

int knapSack(std::vector<int> _values,std::vector<int> _weights, int _maxCapacity) {
	if (_values.size() != _weights.size())
		return 0;

	// Map to store weights with profits of each item
	std::map<int, std::pair<int, int>> uMap;

	// Making Pairs and inserting
	// into the map
	for (int i{ 0 }; i < _values.size(); ++i)
		uMap.emplace(i, std::pair<int, int>{_values[i], _weights[i]});

	//std::set<std::vector<std::pair<int, int>>> set_sol;
	int result = INT_MIN;
	int remaining_weight;
	int sum = 0;

	
	return result;
}

int main()
{
	std::vector<int>	values	{ 1, 4, 8, 5 },
						weights{ 3, 3, 5, 6 };
	int capacity{ 7 };
	
	int maximum = knapSack(values, weights, capacity);
	std::cout << "Maximum Profit = ";
	std::cout << maximum;
	
	return 0;
}