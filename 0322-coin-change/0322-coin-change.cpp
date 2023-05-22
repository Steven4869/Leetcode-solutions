class Solution {
public:
    int solve(vector<int>&coins, int amount, vector<int>&dp){
        //Base Case 
        //If the amount is 0 then return 0
        if(amount==0)
            return 0;
        //If it's negative then return INT_MAX
        if(amount<0)
            return INT_MAX;
        
        int minCoins = INT_MAX;
        if(dp[amount]!=-1){
            return dp[amount];
        }
        //Traverse the array 
        for(int i=0;i<coins.size();i++){
            //Get the answer
            int ans = solve(coins, amount - coins[i], dp);
            if(ans!=INT_MAX){
                //1 for the current coin
                minCoins = min(minCoins, 1+ans);
            }
        }
        return dp[amount]= minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        int ans = solve(coins, amount, dp);
        return ans==INT_MAX?-1:ans;
    }
};