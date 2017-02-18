#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void encrypt(string s);

int main(){
    string s;
    cin >> s;
    encrypt(s);
    return 0;
}

void encrypt(string s)
{
	int str_len = s.size();
	int num_rows = sqrt(str_len);
	int num_cols = str_len/num_rows;
	if (num_cols * num_rows < str_len) num_cols++;
	while (abs(num_cols - num_rows) > 1) {
		if (num_rows > num_cols) {
			num_cols++;
			num_rows--;
		} else {
			num_rows++;
			num_cols--;
		}
	}
	vector<string> encrypted_parts;
	for (int i = 0; i < num_cols; i++) {
		encrypted_parts.push_back("");
	}
	for (int i = 0; i < str_len; i++) {
		encrypted_parts[i % num_cols] += s[i];
	}
	for (int i = 0; i < num_cols; i++) {
		cout << encrypted_parts[i] << " ";
	}
	cout << endl;
}