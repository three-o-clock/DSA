#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<long long> st;

        // "10 + (3 - 5)"

        long long number = 0; 
        long long result = 0;
        int sign = 1; // 1 -> +ve | -1 -> -ve 

        int len = s.length();

        for(int i = 0; i < len; i++) {
            if(isdigit(s[i])) {
                // form the number
                number = (number * 10) + (s[i] - '0');
            } else if(s[i] == '+') {
                result += (number * sign);
                number = 0;
                sign = 1;
            } else if(s[i] == '-') {
                result += (number * sign);
                number = 0;
                sign = -1;
            } else if(s[i] == '(') {
                st.push(result);
                st.push(sign);

                number = 0;
                result = 0;
                sign = 1;
            } else if(s[i] == ')') {
                int last_sign = st.top(); st.pop(); // sign of the result outside the bracket
                int last_result = st.top(); st.pop(); // result outside the bracket 

                result += (number * sign); // result inside the bracket
                number = 0; // reset number to form new numbers

                result = result * last_sign;
                result += last_result;
            }
        }

        result += (number * sign);

        return result;
    }
};

int main() {

    return 0;
}