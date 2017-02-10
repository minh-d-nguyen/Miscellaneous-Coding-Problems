#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string> &A);

int main()
{
    vector<string> A;
    A.push_back("5");
    A.push_back("1");
    A.push_back("2");
    A.push_back("+");
    A.push_back("4");
    A.push_back("*");
    A.push_back("+");
    A.push_back("3");
    A.push_back("-");
    cout << evalRPN(A) << endl;
}

bool has_any_digits(const std::string& s)
{
    return std::any_of(s.begin(), s.end(), ::isdigit);
}

int evalRPN(vector<string> &A) {
    stack<int> nums;
    int result = 0;
    unsigned len = A.size();

    for (unsigned i = 0; i < len; i++) {
        if (has_any_digits(A[i])) {
            cout << "Push: " << stoi(A[i]) << endl;
            nums.push(stoi(A[i]));
        } else {
            char op = A[i][0];
            if (nums.size() < 2)  return -1;
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            cout << num1 << op << num2 << endl;
            switch (op) {
                case '+': result = num1 + num2; break;
                case '-': result = num2 - num1; break;
                case '*': result = num1 * num2; break;
                case '/':
                    if (num1 == 0) return -1;
                    else result = num2/num1; break;
                default: return -1;
            }
            nums.push(result);
            cout << "result: " << nums.top() << endl;
        }
    }
    return nums.top();
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
