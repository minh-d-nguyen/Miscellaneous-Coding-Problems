/*
 Problem: Given a set of distinct integers, print the size of a maximal subset 
 where the sum of any 2 numbers in it is not evenly divisible by k (k given).

 Solution approach: Count the number of elements with remainder i when divided
 by k for all i, then from this result for any pair of number j and k - j add the
 greater number of occurences to the maximal list.
 Solution time complexity: O(max(n, k))
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int num_non_div_subset(vector<int> &num_list, int n, int k);

int main() {
    int n, k, new_elem;
    cin >> n >> k;
    vector<int> num_list;
    for (int i = 0; i < n; i++) {
        cin >> new_elem;
        num_list.push_back(new_elem);
    }
    cout << num_non_div_subset(num_list, n, k) << endl;
}

int num_non_div_subset(vector<int> &num_list, int n, int k)
{
	vector<int> remainder_count;
	int max_subset = 0;
	for (int i = 0; i < k; i++) {
		remainder_count.push_back(0);
	}
	for (int i = 0; i < n; i++) {
		int index = num_list[i] % k;
		remainder_count[index]++;
	}

	if (remainder_count[0] > 0) max_subset++;
	for (int i = 1; i < k/2; i++) {
		max_subset += max(remainder_count[i], remainder_count[k - i]);
	}
	if (k % 2 != 0 && k != 1) {
		max_subset += max(remainder_count[k/2], remainder_count[k - k/2]);
	} else if (k%2 == 0 && remainder_count[k/2] > 0) {
		max_subset += 1;
	}
	return max_subset;
}
