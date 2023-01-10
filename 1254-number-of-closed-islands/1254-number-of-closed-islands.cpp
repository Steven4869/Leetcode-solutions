class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols){
        //Base boundary condition 
        if(i<0||i>=rows||j<0||j>=cols||grid[i][j]==1)
            return;
        grid[i][j]=1;
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i, j-1, rows, cols);
        dfs(grid, i, j+1, rows, cols);
    }
    int closedIsland(vector<vector<int>>& grid) {
        //The idea is to make the boundary 0s => 1 to only count the inner 0s surrounded by 1s 
        //In this way we'll count the number of toal closed islands 
        //Logic to go with is DFS 
        
        //Approach 
        //1. Get rows and cols
        //2. Make the first row, col and last row,col 1 so that it'll be surrounded by water 
        //3. Make the DFS Call for the remaining 0 to make it into closed island
        //Note: No need to use visited array as we are changing this grid only  
        
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
                if(grid[i][j]==0){
                    dfs(grid, i, j, rows, cols);
                    count++;
                }
            }
        }
        return count;
        
        
    }
};