class Solution {
public:
    int solve(vector<int>&prices, int buy, int index){
        //Base Case 
        if(index == prices.size())
            return 0;
        int profit =0;
        
        //If the buying of stock is allowed 
        if(buy){
            //Stock Bought, so representing it as negative, stock not bought so skipping it
            //Take the maximum out of those 
            profit = max((-prices[index])+solve(prices,0,index+1), 0 + solve(prices, 1, index+1));
        }
        else{
            //If buying is not true then we can sell
            //Now we can sell it or skip to the next index 
            profit = max((prices[index])+solve(prices,1,index+1), 0 + solve(prices, 0, index+1));
        }
        return profit;
    }
    int solveMemo(vector<int>&prices, int buy, int index, vector<vector<int>>&dp, int &fee){
        //Base Case 
        if(index == prices.size())
            return 0;
        int profit =0;
        
        if(dp[buy][index]!=-1){
            return dp[buy][index];
        }
        
        //If the buying of stock is allowed 
        if(buy){
            //Stock Bought, so representing it as negative, stock not bought so skipping it
            //Take the maximum out of those 
            profit = max((-prices[index])+solveMemo(prices,0,index+1, dp,fee), 0 + solveMemo(prices, 1, index+1, dp,fee));
        }
        else{
            //If buying is not true then we can sell
            //Now we can sell it or skip to the next index 
            profit = max((prices[index])+solveMemo(prices,1,index+1, dp,fee)-fee, 0 + solveMemo(prices, 0, index+1, dp,fee));
        }
        return dp[buy][index]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        //We have three ways, one to buy, one to skip and one to sell it
        //We will be setting up buy=1 => allowed to buy the stock 
        //If the buy = 0 => Not allowed to buy 
        
        // return solve(prices, 1, 0);
        
        //Using Memoisation 
        vector<vector<int>>dp(2, vector<int>(prices.size()+1, -1));
        return solveMemo(prices, 1, 0, dp, fee);
    }
};