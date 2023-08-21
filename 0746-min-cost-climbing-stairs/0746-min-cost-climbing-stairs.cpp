class Solution {
public:
    int solve(vector<int>&cost, int n){
        //Base Case 
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        
        int ans;
        return ans = min(solve(cost, n-1), solve(cost, n-2)) + cost[n];
    }
     int solveMemo(vector<int>&cost, int n, vector<int>&dp){
        //Base Case 
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        if(dp[n]!=-1)
            return dp[n];
        int ans = min(solveMemo(cost, n-1, dp), solveMemo(cost, n-2, dp)) + cost[n];
         return dp[n] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // int ans = min(solve(cost, n-1), solve(cost, n-2));
        // return ans;
        vector<int>dp(n+1, -1);
        int ans = min(solveMemo(cost, n-1, dp), solveMemo(cost, n-2, dp));
        return ans;
    }
};