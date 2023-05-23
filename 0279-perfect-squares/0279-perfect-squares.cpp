class Solution {
public:
    int solve(int n, vector<int>&dp){
        //Base Case 
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int result = INT_MAX;
        for(int i=1;i*i<=n;i++){
            int ans = solve(n-i*i, dp)+1;
            result = min(result, ans);
        }
        return dp[n]=result;
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};