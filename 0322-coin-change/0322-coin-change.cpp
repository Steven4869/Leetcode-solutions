class Solution {
public:
    
    int solve(vector<int>&coins, int amount){
        if(amount<0)
            return INT_MAX;
        
        if(amount == 0)
            return 0;
        
        int minCoins = INT_MAX;
        
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins, amount - coins[i]);
            if(ans!=INT_MAX)
                minCoins = min(minCoins, 1+ans);
        }
        return minCoins;
    }
    
    int solveMemoisation(vector<int>&coins, int amount, vector<int>&dp){
        if(amount == 0)
            return 0;
        if(amount<0)
            return INT_MAX;
        if(dp[amount]!=-1)
            return dp[amount];
        int minCoins = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveMemoisation(coins, amount - coins[i], dp);
            if(ans!=INT_MAX)
                minCoins = min(minCoins, 1+ans);
        }
        return dp[amount]=minCoins;
    }
    
    int solveTabulation(vector<int>&coins, int amount){
        vector<int>dp(amount+1, INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=amount;i++){
            for(auto coin:coins){
                if(coin<=i && dp[i-coin]!=INT_MAX)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        
        return dp[amount] == INT_MAX?-1:dp[amount];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        //Recursion 
        // int result = solve(coins, amount);
        // if(result != INT_MAX)
        //     return result;
        // return -1; 
        
        //Memoisation 
        vector<int>dp(amount+1, -1);
        int result = solveMemoisation(coins, amount, dp);
        if(result != INT_MAX)
            return result;
        return -1;
    }
};