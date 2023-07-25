class Solution {
public:
    int solve(int n){
        if(n<=1)
            return 1;
        
        int result = 0;
        for(int i=1;i<=n;i++){
            result = result + solve(i-1)*solve(n-i);
        }
        return result;
    }
    int solveMemo(int n, vector<int>&dp){
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        
        int result = 0;
        for(int i=1;i<=n;i++){
            result = result + solveMemo(i-1, dp)*solveMemo(n-i, dp);
        }
        return dp[n] = result;
    }
    int numTrees(int n) {
        //Recursive
        // return solve(n);
        
        //Memo
        vector<int>dp(n+1, -1);
        return solveMemo(n, dp);
    }
};