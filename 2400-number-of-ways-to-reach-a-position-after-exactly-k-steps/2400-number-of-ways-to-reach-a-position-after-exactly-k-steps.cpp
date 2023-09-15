class Solution {
public:
    int mod = 1e9+7;
    int dp[3004][1001];
    int solve(int startPos, int endPos, int k){
        //Base Case 
        if(abs(startPos-endPos)>k)
            return 0;
        if(k==0 && startPos == endPos)
            return 1;
        if(k==0)
            return 0;
        if(dp[startPos][k]!=-1)
            return dp[startPos][k];
        return dp[startPos][k] = ((solve(startPos+1, endPos, k-1)%mod)+(solve(startPos-1,endPos, k-1)%mod))%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        // vector<vector<int>>dp(1001, vector<int>(1001,-1));
        memset(dp, -1, sizeof(dp));
        startPos = startPos +1000;
        endPos = endPos +1000;
        return solve(startPos, endPos, k);
    }
};