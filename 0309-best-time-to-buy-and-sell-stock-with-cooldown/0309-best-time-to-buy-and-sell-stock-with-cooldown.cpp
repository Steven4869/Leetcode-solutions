class Solution {
public:
    
    int solve(vector<int>&prices, int buy, int index, vector<vector<int>>&dp){
        if(index >=prices.size())
            return 0;
        
        if(dp[buy][index]!=-1)
            return dp[buy][index];
        
        int profit = 0;
        if (buy){
            profit = max((-prices[index])+solve(prices, 0, index+1, dp),
                        0 + solve(prices, 1, index+1, dp));
        }
        else{
            profit = max((prices[index]+solve(prices, 1, index+2, dp)),
                        0 + solve(prices, 0, index+1, dp));
        }
        
        return dp[buy][index] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(2, vector<int>(n+1, -1));
        return solve(prices, 1, 0, dp);
    }
};