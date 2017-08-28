/*
 * Complete the function below.
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string findFirstRepeatingChar(string s);

int main() {
    string s;
    cin >> s;
    cout << findFirstRepeatingChar(s) << endl;
    return 0;
}

string findFirstRepeatingChar(string s) {
    int len = s.size();   
    // Array counting the number of occurences of each character
    int num_occur[52];   
    // Array keeping track of the order in which a character appears
    // For example: If order[0] =  2, it means character 'a' (index 0 in the list) 
    // is the 3rd character to appear in the string
    int order[52];
    
    int curr_order = 0;
    
    for (int i = 0; i < 52; i++) {
        num_occur[i] = 0;
        order[i] = -1;
    }
    
    // Loop through the string, count the number of appearances and keep track
    // of appearance order
    for (int i = 0; i < len; ++i) {
        int index = 0;
        if (islower(s[i])) {
            index = s[i] - 'a';
        } else {
            index = s[i] - 'A' + 26;
        }
        num_occur[index]++;
        if (order[index] == -1) {
            order[index] =  curr_order;
            curr_order++;
        }
    }
    
    // Index of the duplicated character that appears first
    int curr_order_dup = len;
    char to_return = ' ';

    // Find the duplicated character that appears first
    for (int i = 0; i < 52; i++) {
        if (num_occur[i] > 1 && order[i] < curr_order_dup) {
            if (i < 26) {
                to_return = 'a' + i;
            } else {
                to_return = 'A' + i - 26;
            }
            curr_order_dup = order[i];
        }
    }

    //The string to be returned
    string ret = "";
    ret += to_return;

    return ret;
}

