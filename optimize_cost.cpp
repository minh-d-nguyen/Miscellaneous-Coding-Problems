#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_cost(vector<int> &nums);

int main() {
    int num_tests;
    cin >> num_tests;
    for (int i = 0; i < num_tests; i++) {
        int list_size;
        cin >> list_size;
        vector<int> nums;
        for (int j = 0; j < list_size; ++j)
        {
        	int temp;
        	cin >> temp;
        	nums.push_back(temp);
        }
        cout << max_cost(nums) << endl;
    }
    return 0;
}

int max_cost(vector<int> &nums)
{
	if (nums.size() < 2) return 0;
	int bottom_cost = nums[0] - 1;
	int peak_cost = nums[1] - 1;
	int bot_case = 0;
	int peak_case = 0;

	for (int i = 2; i < nums.size(); i++) {
		if (bottom_cost > peak_cost + nums[i - 1] - 1) {
			bot_case = 0;
		} else {
			bot_case = 1;
		}

		if (peak_cost + abs(nums[i - 1] - nums[i]) > bottom_cost + nums[i] - 1) {
			peak_case = 0;
		} else {
			peak_case = 1;
		}

		int peak_cost_copy = peak_cost;
		int bottom_cost_copy = bottom_cost;

		if (bot_case == 0) {

        } else {
			bottom_cost = peak_cost_copy + nums[i - 1] - 1;
		}

		if (peak_case == 0) {
			peak_cost += abs(nums[i] - nums[i - 1]);
		} else {
			peak_cost = bottom_cost_copy + nums[i] - 1;
		}
	}

	return max(peak_cost, bottom_cost);
}
