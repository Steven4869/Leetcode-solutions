class Solution {
public:
    int solve(int index, int pending, int endIndex, vector<int>&slices, vector<vector<int>>&dp){
        if(index>=endIndex || pending == 0)
            return 0;
        
        if(dp[index][pending]!=-1)
            return dp[index][pending];
        int take = slices[index] + solve(index+2, pending-1, endIndex, slices, dp); 
        int notTake = 0 + solve(index+1, pending, endIndex, slices, dp);
        return dp[index][pending] = max(take, notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n/3;
        vector<vector<int>>dp1(n+1, vector<int>(k+1, -1));
        vector<vector<int>>dp2(n+1, vector<int>(k+1, -1));
        int case1 = solve(0, k, n-1, slices, dp1);
        int case2 = solve(1, k, n, slices, dp2);
        return max(case1, case2);
    }
};