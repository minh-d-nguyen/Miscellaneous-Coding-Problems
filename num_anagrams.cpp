#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int num_anagrams(string s);

int main() {
    int num_cases = 0;
    cin >> num_cases;
    for (int i = 0; i < num_cases; i++) {
        string s;
        cin >> s;
        cout << num_anagrams(s) << endl;
    }
    return 0;
}

int num_anagrams(string s)
{
    int ret = 0;
    int len = s.size();
    unordered_multimap<string, string> anagram_groups;
    for (int i = 0; i < len; i++) {
        string curr = "";
        for (int j = i; j < len; j++) {
            curr += s[j];
            string key = curr;
            sort(key.begin(), key.end());
            anagram_groups.insert({key, curr});
        }
    }
    
    for (auto it = anagram_groups.begin(); it != anagram_groups.end();) {
        auto range = anagram_groups.equal_range(it->first);
        int size_range = distance(range.first, range.second);
        int num_pairs = size_range*(size_range - 1);
        num_pairs /= 2;
        ret += num_pairs;
        it = range.second;
    }
    
    return ret;
}