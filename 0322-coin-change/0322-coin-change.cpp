class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount +1, INT_MAX-1);
        
        //Base case 
        dp[0]=0;
        //get the amount 
        for(int a=1;a<=amount;a++){
            for(int c=0;c<coins.size();c++){
                if(a-coins[c]>=0)
                    dp[a]=min(dp[a], 1+dp[a-coins[c]]);
            }
        }
        if(dp[amount]!=INT_MAX-1)
            return dp[amount];
        else 
            return -1;
        return -1;
    }
};