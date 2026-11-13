class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();

        vector<int> ahead(2, 0), curr(2, 0);

        for(int idx = n - 1; idx >= 0; idx--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if(buy) {
                    profit = max(-arr[idx] + ahead[0], ahead[1]);
                }
                else {
                    profit = max(arr[idx] + ahead[1], ahead[0]);
                }

                curr[buy] = profit;
            }

            ahead = curr;
        }

        return curr[1];
    }
};