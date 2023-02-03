class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j){
        if(i>=m||j>=n)
            return 0;
        if(obstacleGrid[i][j])
            return 0;
        if(i==m-1&&j==n-1&&!obstacleGrid[i][j])
            return 1;
        if(dp[i][j])
            return dp[i][j];
        return dp[i][j] = solve(obstacleGrid, m, n, i+1, j) + solve(obstacleGrid, m, n, i, j+1);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        return solve(obstacleGrid, m, n, 0, 0);
    }
};