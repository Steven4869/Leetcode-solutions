class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& obstacleGrid){
        if(i==m-1 && j==n-1 && obstacleGrid[i][j] == 0)
            return 1;
        if(i>=m || j>=n || obstacleGrid[i][j]==1)
            return 0;
        
        int ans = solve(m,n,i+1,j,obstacleGrid)+solve(m,n,i,j+1,obstacleGrid);
        return ans;

    }
    int solveMemo(int m, int n, int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1 && obstacleGrid[i][j] == 0)
            return 1;
        if(i>=m || j>=n || obstacleGrid[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = solveMemo(m,n,i+1,j,obstacleGrid, dp)+solveMemo(m,n,i,j+1,obstacleGrid, dp);
        return dp[i][j] = ans;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        // return solve(m, n, 0, 0, obstacleGrid);
        return solveMemo(m, n, 0, 0, obstacleGrid, dp);
        
    }
};