#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct elem {
    int value;
    int index;
};

vector<int> twoSum(const vector<int> &A, int B);

int main()
{
    vector<int> A;
    A.push_back(2);
    A.push_back(-3);
    A.push_back(4);
    A.push_back(-7);
    A.push_back(-6);
    A.push_back(5);
    A.push_back(1);
    std::vector<int> v = twoSum(A, 3);
    cout << v[0] << " " << v[1] << endl;
    return 0;
}

vector<int> twoSum(const vector<int> &A, int B) {
    vector<vector<elem> > remainder_groups;
    vector<elem> empty;
    vector<int> ret;
    int B_abs = B;
    if (B < 0) B_abs = -B;

    for (int i = 0; i < B_abs; i++) {
        remainder_groups.push_back(empty);
    }
    
    int len = A.size();
    for (int i = 0; i < len; i++) {
        int remainder = A[i] % B_abs;
        int search_size = remainder_groups[(B_abs - remainder) % B_abs].size();
        for (int j = 0; j < search_size; j++) {
            if (remainder_groups[(B_abs - remainder) % B_abs][j].value == B - A[i]) {
                ret.push_back(remainder_groups[(B_abs - remainder) % B_abs][j].index + 1);
                ret.push_back(i + 1);
                return ret;
            }
        }
        elem temp;
        temp.value = A[i];
        temp.index = i;
        remainder_groups[remainder].push_back(temp);
    }
    return ret;
 
}