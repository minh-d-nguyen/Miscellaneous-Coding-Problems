/*
 Problem: Given a word s, rearrange the letters of s to construct another word w
 in such a way that w is lexicographically greater than s. In case of multiple 
 possible answers, find the lexicographically smallest one among them.

 Solution approach: Use the following algorithm:
 - If the characters in s are decreasing (not strictly), then there is no answer.
 - Else: 
   + If s[0] is the "maximum" character in the set, we recursively call the
   algorithm with the string s[1]...s[s.len - 1] and return s[0] + the resulting
   string.
   + Else:
     .) If the substring s[1]...s[s.len - 1] is decreasing, find the smallest
     character greater than s[0], swap, then return s[0]_new + sorted remaining
     sublist.
     .) Else, recurse on the string s[1]...s[len - 1] and return s[0] +
     resulting string.

 Solution time complexity: O(n^2)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const string NOT_FOUND = "no answer";

string next_lexi(string s);
string sort_string(string s);

int main() {
	string s;
    int n;
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
       	cout << next_lexi(s) << endl;
    }
    return 0;
}


string next_lexi(string s)
{
	if (s == "") return NOT_FOUND;
	int num_reverse_order = 0;
	char curr_max = s[0];
	int len = s.size();

	for (int i = 0; i < len - 1; i++) {
		if (s[i] < s[i + 1]) num_reverse_order++;
		if (s[i] > curr_max) curr_max = s[i];
	}
	if (s[len - 1] > curr_max) curr_max = s[len - 1];
	if (num_reverse_order == 0) return NOT_FOUND;
	if (curr_max == s[0]) {
		string substring = s.substr(1, len - 1);
		return s[0] + next_lexi(substring);
	}

	num_reverse_order = 0;

	for (int i = 1; i < len - 1; i++) {
		if (s[i] < s[i + 1]) num_reverse_order++;
	}

	int swap_ind = 0;

	if (num_reverse_order == 0) {
		char curr_swap_char = '{';
		for (int i = 0; i < len; i++) {
			if (s[i] > s[0] && s[i] < curr_swap_char) {
				curr_swap_char = s[i];
				swap_ind = i;
			}
		}
		char temp = s[0];
		s[0] = s[swap_ind];
		s[swap_ind] = temp;
		return s[0] + sort_string(s.substr(1, len - 1));
	}

	return s[0] + next_lexi(s.substr(1, len - 1));
}

string sort_string(string s)
{
	int num_occur[26];
	string sorted = "";
	int len = s.size();
	for (int i = 0; i < 26; i++) {
		num_occur[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		num_occur[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < num_occur[i]; j++) {
			sorted += (char) 'a' + i;
		}
	}
	return sorted;
}