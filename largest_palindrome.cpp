/*
 Problem: Given a number n and a number s, determined the largest number k, which
 is a palindrome, that can be obtained from a after no more than s modifications
 of n's digits.

 Solution approach: First count the number of unequal pairs m. Each of these pairs
 needs at least 1 modification -> we have (s - m) "free modifications". With these
 modification, alter the most significant digits to 9 when possible.

*/

string largest_palin(string number, int len, int k);

int main(){
    int n;
    int k;
    cin >> n >> k;
    string number;
    cin >> number;
    string result = largest_palin(number, n, k);
    cout << result << endl;
    return 0;
}

string largest_palin(string num, int len, int k)
{
    set<int> bad_index;
    for (int i = 0; i < len/2; i++) {
        if (num[i] != num[len - 1 - i]) {
            bad_index.insert(i);
        }
    }
    unsigned num_bad_index = bad_index.size();
    int num_free = k - num_bad_index;
    int n = len;
    if (num_free < 0) return "-1";
    for (int i = 0; i < len/2; i++) {
        if (bad_index.find(i) == bad_index.end() && num_free > 1 && num[i] != '9') {
            num[i] = '9';
            num[n - 1 - i] = '9';
            num_free -= 2;
        } else if (bad_index.find(i) != bad_index.end()) {
            if (num[i] == '9') {
                num[n - 1 - i] = '9';
            } else if (num[n - 1 - i] == '9') {
                num[i] = '9';
            } else if (num_free > 0) {
                num[i] = '9';
                num[n - 1 - i] = '9';
                num_free--;
            } else {
                char maxc = max(num[i], num[n - 1 - i]);
                num[i] = maxc;
                num[n - 1 - i] = maxc;
            }
        }
    }
    if (len % 2 == 1 && num_free > 0) {
        num[len/2] = '9';
    }
    return num;
}