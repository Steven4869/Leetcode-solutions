class Solution {
public:
    int dfs(vector<vector<int>>&grid, int sr, int sc, int rows, int cols){
        //BOundary COndition
        if(sr<0||sr>=rows||sc<0||sc>=cols||grid[sr][sc]==0){
            return 1;
        }
        if(grid[sr][sc]==-1)
            return 0;
        grid[sr][sc]=-1;
        return dfs(grid, sr-1, sc, rows, cols)+
        dfs(grid, sr+1, sc, rows, cols)+
        dfs(grid, sr, sc-1, rows, cols)+
        dfs(grid, sr, sc+1, rows, cols);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    count = dfs(grid, i, j, rows, cols);
                }
            }
        }
        return count;
    }
};