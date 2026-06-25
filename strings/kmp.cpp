#include<bits/stdc++.h>

using namespace std;

vector<int> buildLPS(string &pattern);

bool KMP(string &txt, string &pattern) {
    if(pattern.empty()) return true;
    vector<int> LPS = buildLPS(pattern);

        int n = txt.length(), m = pattern.length();
        int i = 0, j = 0;

        while(i < n) {
            if(txt[i] == pattern[j]) {
                i++, j++;
                
                if(j == m) return true;
            }

            else {
                if(j != 0) j = LPS[j - 1];
                else i++;
            }
        }

    return false;
}

vector<int> buildLPS(string &pattern) {
        int n = pattern.size();
        vector<int> LPS(n);
        int len = 0;
        LPS[0] = 0; // by convention
        int i = 1;

        while(i < n) {
            if(pattern[i] == pattern[len]) {
                len++;
                LPS[i] = len;
                i++;
            }

            else {
                if(len != 0) {
                    len = LPS[len - 1];
                }
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

    return LPS;
}



