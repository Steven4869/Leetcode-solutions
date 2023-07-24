class Solution {
public:
    void dfs(int row, int col, int emptyCells, int& count, vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[row][col] == 2) {
        if (emptyCells == 0) {
            count++;
        }
        return;
    }

    // Mark the cell as visited
    int temp = grid[row][col];
    grid[row][col] = -1;

    // Explore all four directions
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] != -1) {
            dfs(newRow, newCol, emptyCells - 1, count, grid);
        }
    }

    // Restore the cell to its original state (backtrack)
    grid[row][col] = temp;
}

    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;
        int emptyCell = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        int startRow, startCol;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    startRow=i;
                    startCol=j;
                }
                else if(grid[i][j] == 0)
                    emptyCell++;
            }
        }
        
        dfs(startRow, startCol, emptyCell+1, count, grid);
        return count;
    }
};