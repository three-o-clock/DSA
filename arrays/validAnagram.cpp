#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isAnagram(string &s, string &t) {
        if(s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s[i] != t[i]) return false;
        }

        return true;
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


// class Solution {
// public:
//     bool anagramStrings(string &s, string &t) {
//         // Edge Cases
//         if (s.length() != t.length()) return false;

//         // To store the count of each character
//         vector<int> count(26, 0);

//         // Count occurence of each character in first string 
//         for (char c : s) count[c - 'a']++;

//         // Decrement the count for each character in the second string
//         for (char c : t) count[c - 'a']--;

//         // Check for count of every character
//         for (int i : count) {
//             // If the count is not zero
//             if (i != 0) return false; // Return false
//         }

//         // Otherwise strings are anagram
//         return true;
//     }
// };



