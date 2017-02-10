/* Problem: 
   Given an absolute path for a file (Unix-style), simplify it.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<string> directories;
    string result = "";
    string folder = "";
    unsigned len = A.size();
    for (unsigned i = 0; i < len; i++) {
        if (A[i] == '/') {
            unsigned j = 0;
            for (j = i + 1; j < len && A[j] != '/'; j++) {
                folder += A[j];
            }
            if (folder != "" && folder != ".") {
                if (folder == ".." && directories.size() > 0) directories.pop();
                else if (folder != "..") directories.push(folder);
            }
            i = j - 1;
        }
        folder = "";
    }
    stack<string> directories_rev;

    while (directories.size() > 0) {
        folder = directories.top();
        directories.pop();
        directories_rev.push(folder);
    }

    while (directories_rev.size() > 0) {
        folder = "/";
        folder = folder + directories_rev.top();
        directories_rev.pop();
        result += folder;
    }
    return result;
}