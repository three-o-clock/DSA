class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // int profit = helper(0, n, 1, arr, dp);

        for(int idx = n - 1; idx >= 0; idx--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if(buy) {
                    profit = max(-arr[idx] + dp[idx + 1][0], dp[idx + 1][1]);
                }
                else {
                    profit = max(arr[idx] + dp[idx + 1][1], dp[idx + 1][0]);
                }

                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];
    }
};