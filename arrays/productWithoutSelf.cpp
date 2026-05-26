class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product;
        int n = nums.size();
        
        // prefix 
        vector<int> prefix;
        vector<int> suffix;
        for(int i = 0; i < n; i++) suffix.push_back(1), prefix.push_back(1);

        for(int i = 1; i < n; i++) {
            // product = prefix.back() * nums[i - 1];
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        
        // suffix
        for(int i = n - 2; i >= 0; i--) {
            // product = suffix[i + 1] * nums[i + 1];
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++) {
            // product = prefix[i] * suffix[i];
            ans.push_back(prefix[i] * suffix[i]);
        }

        return ans;
    }
};