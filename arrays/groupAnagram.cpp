class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> occurences;

        for(auto &i : strs) {
            int count[26] = {0};
            for(auto &c : i) {
                count[c - 'a']+= 1;
            }
            string key = to_string(count[0]);
            for(int k = 0; k < 26; k++) {
                key += ',' + to_string(count[k]);
            }
            occurences[key].push_back(i);
        }
        vector<vector<string>> result;
        for(const auto& pair : occurences) {
            result.push_back(pair.second);
        }
        return result;
    }
};
