class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        // If k is greater than or equal to n/2, it can be treated as unlimited transactions
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                maxProfit += max(0, prices[i] - prices[i - 1]);
            }
            return maxProfit;
        }
        
        // Create a DP array to store the maximum profit for up to k transactions
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= k; ++i) {
            int maxDiff = -prices[0];
            for (int j = 1; j <= n; ++j) {
                // Calculate the maximum profit by either not buying or selling on the current day
                dp[i][j] = max(dp[i][j - 1], prices[j - 1] + maxDiff);
                // Update the maximum difference seen so far
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j - 1]);
            }
        }
        
        return dp[k][n];
    }

};