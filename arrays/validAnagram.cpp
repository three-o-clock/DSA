#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isAnagram(string &s, string &t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        int len = s.length();

        for(int i = 0; i < len; i++) {
            sMap[s[i]] += 1;
            tMap[t[i]] += 1;
        }

        return sMap == tMap
    }
};


int main() {
    Solution solution;
    string str1 = "INTEGER";
    string str2 = "cat";
    bool result = solution.isAnagram(str1, str2);
    cout << (result ? "True" : "False") << endl;
    return 0;
}




