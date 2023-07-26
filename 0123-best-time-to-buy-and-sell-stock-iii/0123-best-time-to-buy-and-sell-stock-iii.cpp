class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, int limit){
        //Base Case 
        if(index == prices.size())
            return 0;
        if(limit == 0)
            return 0;
        
        int profit = 0;
        if(buy){
            int buyStock = (-prices[index]) + solve(prices, index+1, 0, limit);
            int skipStock = 0 + solve(prices, index+1, 1, limit);
            profit = max(buyStock, skipStock);
        }
        else{
            int sellStock = prices[index] + solve(prices, index+1, 1, limit-1);
            int skipSell = 0 + solve(prices, index+1, 0, limit);
            profit = max(sellStock, skipSell);
        }
        return profit;
    }
    int solveMemo(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp) {
    // Base Case
    if (index == prices.size() || limit == 0)
        return 0;
    
    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];
    
    int profit = 0;
    if (buy) {
        int buyStock = (-prices[index]) + solveMemo(prices, index + 1, 0, limit, dp);
        int skipStock = solveMemo(prices, index + 1, 1, limit, dp);
        profit = max(buyStock, skipStock);
    } else {
        int sellStock = prices[index] + solveMemo(prices, index + 1, 1, limit - 1, dp);
        int skipSell = solveMemo(prices, index + 1, 0, limit, dp);
        profit = max(sellStock, skipSell);
    }
    return dp[index][buy][limit] = profit;
}

int maxProfit(vector<int>& prices) {
    // Using Memoization
    int limit = 2;
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(limit + 1, -1)));
    return solveMemo(prices, 0, 1, limit, dp);
}
};


