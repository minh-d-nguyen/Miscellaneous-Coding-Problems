/*
 Problem: Given an array of non-negative integers, you are initially 
 positioned at the first index of the array. Each element in the array 
 represents your maximum jump length from that position forward. 
 Determine if you are able to reach the last index.

 Solution approach: Have a max variable storing the current largest 
 reachable index, we mark each position not greater than max "possible", and
 if on the way we find a new max, we update max.

 Solution time complexity: O(n)
 */

int Solution::canJump(vector<int> &A) {
	vector<int> result;
	unsigned n = A.size();
	for (unsigned i = 0; i < n; i++) {
		result.append(0);
	}
	result[0] = 1;
	unsigned max = A[0];
	for (i = 1; i <= max && i < n; i++) {
		A[i] = 1;
		if (A[i] + i > max) {
			max = A[i] + i;
		}
	}
	return result[n - 1];
}
