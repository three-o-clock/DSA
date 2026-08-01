#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string> &wordList) {
        
        unordered_set<string> s(wordList.begin(), wordList.end());
        int n = wordList.size();
        int len = startWord.length();

        vector<vector<string>> ans;

        queue<vector<string>> q;
        q.push({startWord});
        s.erase(startWord);

        while(!q.empty()) {
            int size = q.size();

            vector<string> wordsUsedInLevel;

            while(size--) {
                auto path = q.front();
                q.pop();

                // last word of the path that needs to be further transformed
                string word = path.back();

                // if word == targetWord, push the path in the ans vector 
                if(word == targetWord) ans.push_back(path);

                // if !ans.empty(), then it means that we have found the minimum path. so no further transformations are required 

                if(!ans.empty()) continue;

                // now, transform 

                for(int i = 0; i < len; i++) {
                    char original = word[i];
                    // for each letter in word, change it to all other letters in the alphabet 
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if(s.find(word) != s.end())  {
                            wordsUsedInLevel.push_back(word);

                            path.push_back(word);
                            q.push(path);
                            path.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }

            // once done with the level, erase all the used words from the set 

            for(auto& str : wordsUsedInLevel)  {
                s.erase(str);
            }

            if(!ans.empty()) break;
        }

        return ans;
    }
};

int main() {

    return 0;
}



class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size(); 
        int MOD = 1e9 + 7;

        int left = 0, right = n - 1;

        int numberOfSubsequences = 0;

        vector<int> power(n, 1); // pow(n, 2)

        for(int i = 1; i < n; i++) {
            power[i] = (2 * power[i - 1]) % MOD;
        }

        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                // valid window 
                numberOfSubsequences = (numberOfSubsequences + power[right - left]) % MOD;
                left++;
            }

            else right--;
        }

        return numberOfSubsequences;
    }
};


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size(); 
        int MOD = 1e9 + 7;
        int numberOfSubsequences = 0;

        vector<int> power(n, 1);

        for(int i = 1; i < n; i++) {
            power[i] = (2 * power[i - 1]) % MOD;
        }

        for(int i = 0; i < n; i++) {
            // nums[i] = minimum
            if(2 * nums[i] > target) break;

            int left = i, right = n - 1; 

            while(left <= right) {
                // binary search is finding the maximum value that can be taken with the minimum value i.e nums[i]
                int mid = left + (right - left) / 2;

                if(nums[i] + nums[mid] <= target) {
                    left = mid + 1;
                }

                else right = mid - 1;
            }

            // now, after binary search, i have found the maximum value that can be taken with nums[i]
            numberOfSubsequences = (numberOfSubsequences + power[right - i]) % MOD;

        }

        return numberOfSubsequences;
    }
};

// [3 5 6] 7 
// 2 - 0 = 2 
// pow(2, 2) = 4 
// 3 - take 
// 5 - take or not take
// 6 - take or not take 