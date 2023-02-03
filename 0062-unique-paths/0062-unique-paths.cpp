class Solution {
public:
    int dp[101][101];
    int recur(int m, int n, int i, int j){
        if(i>=m||j>=n)
            return 0;
        if(i==m-1&&j==n-1)
            return 1;
        if(dp[i][j])
            return dp[i][j];
        return dp[i][j] = recur(m,n,i+1,j)+recur(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        return recur(m, n, 0, 0);
    }
};