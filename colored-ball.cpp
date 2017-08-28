#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int num_group(vector<int> v);

int main() {
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cout << num_group(v) << endl;
	return 0;
}

int num_group(vector<int> v)
{
	int len = v.size();
	if (len == 0) return 0;
	int min = v[0];
	for (int i = 1; i < len; i++) {
		if (v[i] < min) min = v[i];
	}

	for (int i = 1; i <= min/2 + 1; i++) {
		for (int k = 1; k >= 0; k--) {
			int num_mem = (min + k)/i;
			bool b = true;
			bool check = false;
			for (int j = 0; j < len && b; j++) {
				int group = v[j]/num_mem;
				int remainder = v[j] - group*num_mem;
				if (check && remainder != num_mem - 1 && remainder != 0 && group < remainder) {
					b = false;
				}
				if (group < remainder && (remainder < num_mem - 1)) {
					b = false;
				} else if (remainder == num_mem - 1 && group < remainder) {
					check = true;
				} 
			}

			if (b == true) {
				if (check == true) {
					num_mem = num_mem - 1;
				}
				int all_group = 0;
				for (int j = 0; j < len; j++) {
					int group = v[j]/(num_mem + 1);
					int rem = v[j] - group*(num_mem + 1);
					if (rem == 0) {
						all_group += group;
					} else if (num_mem - rem - 1 < group) {
						all_group += group + 1;
					} else {
						all_group += v[j]/num_mem;
					}
				}
				return all_group;
			}
		}

	}
	return 0;
}
