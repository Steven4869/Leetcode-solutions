class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols){
        //Base boundary condition 
        if(i<0||i>=rows||j<0||j>=cols||grid[i][j]==0)
            return;
        grid[i][j]=0;
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i, j-1, rows, cols);
        dfs(grid, i, j+1, rows, cols);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //Intialsing rows and cols 
        int rows = grid.size();
        int cols = grid[0].size();
        
        //Checking for the first and last row 
        //Thus we have to traversal col and take out first and last col 
        
        for(int i=0;i<cols;i++){
            //Call DFS function 
            dfs(grid, 0, i, rows, cols), dfs(grid, rows-1, i, rows, cols);
        }
        
        //Checking for the first and last col 
        
        for(int i=0;i<rows;i++){
            dfs(grid, i, 0, rows, cols), dfs(grid, i, cols-1, rows, cols);
        }
        
        //For remaining elements 
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    // count = max(count, dfs(grid, i, j, rows, cols));
                    count++;
                }
            }
        }
        return count;
    }
};