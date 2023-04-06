class Solution {
public:
    //DFS Function
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int &res){
        int rows = grid1.size();
        int cols = grid1[0].size();
        //Base condition 
        if(i<0||i>=rows||j<0||j>=cols)
            return;
        if(grid1[i][j]==0&&grid2[i][j]==1){
            res = false;
        }
        if(grid2[i][j]==0){
            return;
        }
        grid2[i][j]=0;
        
        dfs(grid1, grid2, i-1, j, res);
        dfs(grid1, grid2, i+1, j, res);
        dfs(grid1, grid2, i, j-1, res);
        dfs(grid1, grid2, i, j+1, res);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        //Algorithm
        //1. Get rows and cols of grid 1
        int rows = grid1.size();
        int cols = grid1[0].size();
        
        //Traverse the loop and find island cell in grid 2 then perform dfs call
        int ans =0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid2[i][j]==1){
                    int res=true;
                    dfs(grid1, grid2, i, j, res);
                    ans = ans + res;
                }
            }
        }
        return ans;
    }
};