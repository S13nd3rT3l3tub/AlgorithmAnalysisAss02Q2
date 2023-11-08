#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int knapSack(int C, vector<int> val,vector<int> wt, int n)
{
	// Mapping weights with Profits
	map<int, int> umap;

	set<vector<pair<int, int>>> set_sol;
	// Making Pairs and inserting
	// into the map
	for (int i = 0; i < n; i++) {
		umap.insert({ wt[i], val[i] });
	}

	int result = INT_MIN;
	int remaining_weight;
	int sum = 0;

	// Loop to iterate over all the 
	// possible permutations of array
	do {
		sum = 0;

		// Initially bag will be empty
		remaining_weight = C;
		vector<pair<int, int>> possible;

		// Loop to fill up the bag 
		// until there is no weight
		// such which is less than
		// remaining weight of the
		// 0-1 knapSack
		for (int i = 0; i < n; i++) {
			if (wt[i] <= remaining_weight) {

				remaining_weight -= wt[i];
				auto itr = umap.find(wt[i]);
				sum += (itr->second);
				possible.push_back({ itr->first,
					 itr->second
					});
			}
		}
		sort(possible.begin(), possible.end());
		if (sum > result) {
			result = sum;
		}
		if (set_sol.find(possible) ==
			set_sol.end()) {
			for (auto sol : possible) {
				cout << sol.first << ": "
					<< sol.second << ", ";
			}
			cout << endl;
			set_sol.insert(possible);
		}

	} while (
		next_permutation(wt.begin(),
			wt.end()));
	return result;
}

int main()
{
	std::vector<int>	V{ 1, 4, 8, 5 },
						W{ 3, 3, 5, 6 };
	int C = 7;
	knapSack(C, V, W, V.size());

	return 0;
}
