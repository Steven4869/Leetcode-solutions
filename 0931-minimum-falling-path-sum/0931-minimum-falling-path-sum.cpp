class Solution {
public:
    int minCost(int i, int j, int n, vector<vector<int>>&dp, vector<vector<int>>& matrix){
       
        if(j<0||j==n)
            return INT_MAX;
         if(i==n-1)
            return matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int leftDiagonal = minCost(i+1, j-1, n, dp, matrix);
        int bottom = minCost(i+1, j, n, dp, matrix);
        int rightDiagonal = minCost(i+1, j+1, n,  dp, matrix);
        
        return dp[i][j] = matrix[i][j] + min(leftDiagonal, min(bottom, rightDiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0;i<n;i++){
            ans = min(ans, minCost(0, i, n, dp, matrix));
        }
        return ans;
    }
};