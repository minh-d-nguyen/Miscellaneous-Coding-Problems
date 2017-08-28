#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int R, C, N;
    vector<string> grid;
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        string row;
        for (int j = 0; j < C; j++) {
            char temp;
            cin >> temp;
            row += temp;
        }
        grid.push_back(row);
    }
    
    vector<vector<int> > bomb_state;
    vector<vector<int> > new_bomb_state;
    for (int i = 0; i < R; i++) {
        vector<int> row;
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                row.push_back(-1);
            } else {
                row.push_back(1);
            }
        }
        bomb_state.push_back(row);
        new_bomb_state.push_back(row);
    }
    cout << endl;    
    for (int k = 0; k < N - 1; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                bomb_state[i][j] = new_bomb_state[i][j];
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << new_bomb_state[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << i << " " << j << endl;
                if (bomb_state[i][j] == -1) {
                    new_bomb_state[i][j] = 0;
                } else if (bomb_state[i][j] == 1) {
                    new_bomb_state[i][j] = 2;
                } else if (bomb_state[i][j] == 0) {
                    if (i == 0) {
                        if (j == 0) {
                            if ((C > 1 && bomb_state[0][1] == 2) || (R > 1 && bomb_state[1][0] == 2)) {
                                new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1;
                        } else if (j == C - 1) {
                            if ((C > 1 && bomb_state[0][C - 2] == 2) || (R > 1 && bomb_state[1][C - 1] == 2)) {
                                new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1;
                        } else if (R > 1) {
                            if (bomb_state[0][j - 1] == 2 || bomb_state[0][j + 1] == 2 || bomb_state[1][j] == 2) {
                                new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1;
                        } else {
                            if (bomb_state[0][j - 1] == 2 || bomb_state[0][j + 1] == 2) {
                                new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1;
                        }
                    } else if (i == R - 1) {
                        if (j == 0) {
                            if (bomb_state[R - 1][1] == 2 || bomb_state[R - 2][0] == 2) {
                                new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1;
                        } else if (j == C - 1) {
                            if (bomb_state[R - 1][C - 2] == 2 || bomb_state[R - 2][C - 1] == 2) {
                                new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1;
                        } else {
                            if (bomb_state[R - 1][j - 1] == 2 || bomb_state[R - 1][j + 1] == 2 || 
                                bomb_state[R - 2][j] == 2) {
                                new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1;
                        } 
                    } else if (j == 0) {
                        if (C > 1) {
                            if (bomb_state[i + 1][j] == 2 || bomb_state[i][j + 1] == 2 || 
                                bomb_state[i - 1][j] == 2) {
                                    new_bomb_state[i][j] = -1;
                            } else new_bomb_state[i][j] = 1; 
                        } else {
                            if (bomb_state[i][j + 1] == 2 || 
                                bomb_state[i - 1][j] == 2) {
                                    new_bomb_state[i][j] = -1;
                            }
                        }
                    } else if (j == C - 1) {
                        if (bomb_state[i + 1][j] == 2 || bomb_state[i][j - 1] == 2 || 
                            bomb_state[i - 1][j] == 2) {
                                new_bomb_state[i][j] = -1;
                        } else new_bomb_state[i][j] = 1;
                    } else {
                        if (bomb_state[i + 1][j] == 2 || bomb_state[i][j - 1] == 2 || 
                            bomb_state[i - 1][j] == 2 || bomb_state[i][j + 1] ==  2) {
                                new_bomb_state[i][j] = -1;
                        } else new_bomb_state[i][j] = 1;
                    }
                } else if (bomb_state[i][j] == 2) {
                    new_bomb_state[i][j] = -1; 
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (new_bomb_state[i][j] == -1) {
                cout << '.';
            } else cout << 'O';
        }
        cout << endl;
    }
    
    return 0;
}
