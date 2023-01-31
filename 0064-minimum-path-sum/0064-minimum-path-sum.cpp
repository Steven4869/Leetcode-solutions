class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Similar to the min cost climbing stairs 
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, (vector<int>(n,-1)));
        return minCost(m, n, 0, 0, dp, grid);
    }
    int minCost(int m, int n, int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid){
        //Base cases 
        if(i==m-1&&j==n-1)
            return grid[i][j];
        if(i>=m || j>=n)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        //Recursive Calls
        int x = minCost(m, n, i+1, j, dp, grid);
        int y = minCost(m, n, i, j+1, dp, grid);
        
        int ans = grid[i][j] + min(x, y);
        dp[i][j] = ans;
        return ans;
    }
};