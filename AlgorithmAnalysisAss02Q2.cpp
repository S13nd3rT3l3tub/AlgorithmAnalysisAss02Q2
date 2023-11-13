#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct CompareMemberWeightValue {
	bool operator()(const std::pair<int, int>& _a, const std::pair<int, int>& _b) const {
		return _a.second < _b.second;
	}
};

int KnapsackExploreSolutions(std::vector<int> _values,std::vector<int> _weights, int _maxCapacity) {
	// Unequal number of values given; Unable to run algorithm
	if (_values.size() != _weights.size())
		return 0;

	// Map to store weights with profits of each item
	std::vector<std::pair<int, int>> itemList{};

	// Create pair containing value and weight of item and insert into container
	for (int i{ 0 }; i < _values.size(); ++i)
		itemList.emplace_back(std::pair<int, int>{_values[i], _weights[i]});

	// Variables for permutation looping
	std::set<std::vector<std::pair<int, int>>> solutionSet{};
	int result = INT_MIN;
	int remainingWeight;
	int sum = 0;

	// Output
	std::cout << "Knapsack Capacity: " << _maxCapacity << std::endl;
	
	// Algorithm to systematically explore combinations
	do {
		// Set initial values
		sum = 0;
		remainingWeight = _maxCapacity;
		std::vector<std::pair<int, int>> possibleList{};

		// Loop and fill the knapsack
		for (auto it : itemList) {
			if (it.second <= remainingWeight) {
				remainingWeight -= it.second;
				sum += it.first;
				possibleList.emplace_back(it.first, it.second);
			}
		}

		// Sort the container
		std::sort(possibleList.begin(), possibleList.end());

		// Check if this is the largest profit possible and overwrite if so
		if (result < sum)
			result = sum;

		// If this permutation list does not exist in the overall solution set
		if (solutionSet.find(possibleList) == solutionSet.end()) {
			// Add to it and print out this permutation
			solutionSet.insert(possibleList);

			std::cout << "Permutation Set{ Profit of " << sum << " : ";
			for (auto item : possibleList) {
				std::cout << "[V:" << item.first << "|W:" << item.second << "] ";
			}
			std::cout << "}" << std::endl;
		}

	} while (std::next_permutation(itemList.begin(), itemList.end(), CompareMemberWeightValue()));

	std::cout << "Maximum Profit = " << result << std::endl;
	return result;
}

int main() {
	std::vector<int>	values	{ 1, 4, 8, 5 },
						weights { 3, 3, 5, 6 };
	int capacity{ 7 };
	
	KnapsackExploreSolutions(values, weights, capacity);
	
	return 0;
}