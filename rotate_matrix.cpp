/*
 Problem: Given a square matrix A, rotate the matrix by 90 degree in place 
 (without using any additional data structure)

 Solution approach: In order to avoid 
*/
void rotate(vector<vector<int> > &A) {
    int n = A.size(), max = n - 1, min = 0, temp;
    while (min < max) {
        for (int i = min + 1; i <= max; i++) {
            temp = A[min][i];
            A[min][i] = A[n - 1 - i][min];
            A[n - 1 - i][min] = A[max][n - 1 - i];
            A[max][n - 1 - i] = A[i][max];
            A[i][max] = temp;
        }
        min++;
        max--;
    }
 }
