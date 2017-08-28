#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap_or_rev(std::vector<int> &v);

int main() {
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		v.push_back(inp);
	}
	swap_or_rev(v);	
    return 0;
}

void swap_or_rev(std::vector<int> &v)
{
	int num_dec_sublist = 0;
	int num_rev_order = 0;
	int len = v.size();
	int rev1 = 0;
	int rev2 = 0;

	for (int i = 0; i < len - 1; i++) {
		if (v[i] > v[i+1]) {
			rev1 = i;
			rev2 = i + 1;
			num_rev_order++;
			int j = i + 1;
			while (j < len - 1 && v[j] > v[j + 1]) {
				j++;
				rev2++;
				num_rev_order++;
			}
			i = j;
			num_dec_sublist++;
			break;
		}
	}

	cout << rev1 << " " << rev2 << endl;
	cout << num_rev_order << endl;
	cout << num_dec_sublist << endl;

	if (num_rev_order == 0) {
		cout << "yes" << endl;
		return;
	}

	int swap2 = rev2;
	for (int i = rev2; i < len; i++) {
		if (v[i] < v[rev1])  swap2 = i;
	}

	int temp = v[rev1];
	v[rev1] = v[swap2];
	v[swap2] = temp;

	int count_rev = 0;
	for (int i = 0; i < len - 1; i++) {
		if (v[i] > v[i + 1]) count_rev++;
	}
	if (count_rev == 0) {
		cout << "yes" << endl;
		cout << "swap " << rev1 + 1 << " " << swap2 + 1 << endl; 
		return;
	}

	temp = v[rev1];
	v[rev1] = v[swap2];
	v[swap2] = temp;

	if (num_dec_sublist > 1) {
		cout << "no" << endl;
		return;
	}

	if (rev2 - rev1 == 1) {
		if ((rev2 != len - 1 && v[rev1] > v[rev2 + 1]) || (rev1 != 0 && v[rev2] < v[rev1 - 1])) {
			cout << "no" << endl;
			return;
		}
		cout << "yes" << endl;
		cout << "swap " << rev1 + 1 << " " << rev2 + 1<< endl;
		return;
	} else {
		if (rev2 != len - 1 && v[rev1] > v[rev2 + 1]) {
			cout << "no" << endl;
			return;
		}
		for (int i = rev2 + 1; i < len - 1; i++) {
			if (v[i] > v[i + 1]) {
				cout << "no" << endl;
				return;
			}
		}
		cout << "yes" << endl;
		cout << "reverse " << rev1 + 1<< " " << rev2 + 1<< endl;
	}
}
