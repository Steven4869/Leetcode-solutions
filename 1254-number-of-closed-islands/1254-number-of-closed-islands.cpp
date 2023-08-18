class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j] == 1)
            return;
        
        grid[i][j] = 1;
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i, j+1, rows, cols);
        dfs(grid, i, j-1, rows, cols);
    }
    int closedIsland(vector<vector<int>>& grid) {
        //Make the first, last row as 1
        //Make the first and last col as 1 
        //Then apply the same logic as Number of islands 
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        //Apply for the rows 
        for(int i=0;i<cols;i++){
            dfs(grid, 0, i, rows, cols), dfs(grid, rows-1, i, rows, cols);
        }
        
        //Apply for the cols 
        for(int i=0;i<rows;i++){
            dfs(grid, i, 0, rows, cols), dfs(grid, i, cols-1, rows, cols);
        }
        
        int countIsland = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    dfs(grid, i, j, rows, cols);
                    countIsland++;
                }
            }
        }
        
        return countIsland;
    }
};