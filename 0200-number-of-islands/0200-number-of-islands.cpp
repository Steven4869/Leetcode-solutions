class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols,                    vector<vector<int>>&visited){
        //Base Case
        
        if(i<0 || j<0 || i>=rows || j>=cols || visited[i][j] || grid[i][j]!='1')
            return;
        
        visited[i][j] = 1;
        dfs(grid, i+1, j, rows, cols, visited);
        dfs(grid, i-1, j, rows, cols, visited);
        dfs(grid, i, j+1, rows, cols, visited);
        dfs(grid, i, j-1, rows, cols, visited);
        
}
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>>visited(rows, vector<int>(cols, 0));
        
        int countIsland = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, i, j, rows, cols, visited);
                    countIsland++;
                }
            }
        }
        return countIsland;
    }
};