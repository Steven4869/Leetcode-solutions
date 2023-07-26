class Solution {
public:
    int solve(vector<int>&prices, int buy, int index){
        //Base Case 
        if(index == prices.size())
            return 0;
        
        int profit = 0;
        
        if(buy){
            profit = max((-prices[index]) + solve(prices, 0, index+1),
                        0 + solve(prices, 1, index+1));
        }
        else{
            profit = max(prices[index] + solve(prices, 1, index+1),
                        0 + solve(prices, 0, index+1));
        }
        
        return profit;
    }
    
    int solveMemo(vector<int>&prices, int buy, int              index,vector<vector<int>>&dp){
        
        if(index == prices.size())
            return 0;
        
        if(dp[buy][index]!=-1)
            return dp[buy][index];
        
        int profit = 0;
        if(buy){
            profit = max((-prices[index])+solveMemo(prices, 0, index+1, dp),
                        0 + solveMemo(prices, 1, index+1, dp));
        }
        else{
            profit = max(prices[index] + solveMemo(prices,1, index+1, dp),
                        0 + solveMemo(prices, 0, index+1, dp));
        }
        
        return dp[buy][index] = profit;
    }
    int maxProfit(vector<int>& prices) {
        //Recursion 
        
        // return solve(prices, 1, 0);
        
        //Memoisation 
        int n = prices.size();
        vector<vector<int>>dp(2, vector<int>(n+1, -1));
        return solveMemo(prices, 1, 0, dp);
    }
};