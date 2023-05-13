class Solution {
public:
    const int mod = 1e9+7;
    long long dfs(int low, int high, int zero, int one, int index, vector<long long>&dp){
        //Base Case
        if(index>high){
            return 0;
        }
        
        int result;
        if(dp[index]!=-1){
            return dp[index];
        }
        if(index>=low){
            dp[index]=1;
        }
        else{
            dp[index]=0;
        }
        
        dp[index] = dp[index] + dfs(low, high, zero, one, index+one,dp) + 
                        dfs(low, high, zero, one, index+zero,dp);
        return dp[index]%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(1e5+1, -1);
        return dfs(low, high, zero, one, 0, dp);
    }
};