class Solution {
public:
    //Better Way
    
    int solve(vector<int>& coins, int amount, int index){
        if(amount==0)
            return 0;
        if(amount<0 || index == coins.size())
            return INT_MAX;
        
        int include = solve(coins, amount - coins[index], index);
        
        if(include!=INT_MAX)
            include++;
        
        int exclude = solve(coins, amount, index+1);
        
        return min(include, exclude);
    }
    int solveMemo(vector<int>& coins, int amount, int index, vector<vector<int>>&dp) {
    if (amount == 0)
        return 0;

    if (amount < 0 || index == coins.size())
        return INT_MAX;

    if (dp[index][amount] != -1)
        return dp[index][amount];

    int include = solveMemo(coins, amount - coins[index], index, dp);
    if (include != INT_MAX)
        include++;
    int exclude = solveMemo(coins, amount, index + 1, dp); 

    return dp[index][amount] = min(include, exclude);
}
    int coinChange(vector<int>& coins, int amount) {
        
        //Recursion
        // int result = solve(coins, amount, 0);
        // return result == INT_MAX?-1:result;
        
        //Memoisation 
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int result = solveMemo(coins, amount, 0, dp);
        return result == INT_MAX?-1:result;
    }
};