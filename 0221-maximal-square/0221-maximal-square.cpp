class Solution {
public:
    int solve(vector<vector<char>>& mat, int i, int j, int &maxi){
        //Base Case 
        //Out of bounds condition 
        if(i>=mat.size()||j>=mat[0].size())
            return 0;
        
        //To expand matrix we will be searching for right, bottom and diagonal, starting from first one 
        int right = solve(mat, i, j+1, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);
        
        if(mat[i][j]=='1'){
            int ans = 1 + min(right, min(diagonal, down));
            maxi=max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
        
    }
    int solveMem(vector<vector<char>>& mat, int i, int j, int &maxi, vector<vector<int>>&dp){
        //Base Case 
        //Out of bounds condition 
        if(i>=mat.size()||j>=mat[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        //To expand matrix we will be searching for right, bottom and diagonal, starting from first one 
        int right = solveMem(mat, i, j+1, maxi, dp);
        int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        
        if(mat[i][j]=='1'){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi=max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size()+1, vector<int>(matrix[0].size()+1, -1));
        int maxi = 0;
        solveMem(matrix, 0, 0, maxi, dp);
        return maxi*maxi;
    }
};