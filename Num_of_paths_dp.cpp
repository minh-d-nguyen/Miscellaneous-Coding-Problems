/*
Problem: Given a mxn board of zeros and ones, with zeros representing
empty space and ones representing obstacles, find the number of paths
from cell (0, 0) to cell(m, n) without hitting an obstacle.
A path consists of legal steps: From (x, y) we can go to either (x, y+1)
or (x+1, y)

Solution approach: Dynamic Programming

Solution time complexity: O(m*n)
*/
int NumPaths(vector<vector<int> > &A) {
	vector<vector<int> > results;
	vector<int> row_vector;

	unsigned num_rows = A.size();
	unsigned num_cols = A[0].size();
	for (unsigned j = 0; j < num_cols; j++) {
		row_vector.push(0);
	}

	for (unsigned j = 0; j < num_rows; j++) {
		results.push(row_vector);
	}

	if (A[0][0] != 1) {
		results[0][0] = 1;
	}
	for (unsigned i = 0; i < num_rows; i++) {
		for (unsigned j = 0; j < num_cols; j++) {
			if (i == 0) {
				if (A[i][j] == 1) {
					results[i][j] = 0;
				} else if (j > 0) {
					results[i][j] = results[i][j - 1];
				}
			} else if (j == 0) {
				if (A[i][j] == 1) {
					results[i][j] = 0;
				} else results[i][j] = results[i - 1][j];
			} else {
				results[i][j] =  results[i - 1][j] + results[i][j - 1];
			}
		}
	}
	return results[num_rows - 1][num_cols - 1];
}
