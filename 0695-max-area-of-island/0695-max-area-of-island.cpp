class Solution {
public:
    int dfs(int i, int j, int rows, int cols, vector<vector<int>>& grid, vector<vector<int>>&visited){
        //Base Boundary Condition 
        if(i<0||i>=rows||j<0||j>=cols||visited[i][j]||grid[i][j]==0)
            return 0;
        //Mark it as visited 
        visited[i][j]=1;
        //Call the DFS for four sides 
        return (1+dfs(i-1,j,rows,cols,grid,visited)+dfs(i+1,j,rows,cols,grid,visited)+dfs(i,j-1,rows,cols,grid,visited)+dfs(i,j+1,rows,cols,grid,visited));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //The key idea of this problem is to count the number of 1s attached to adjacent ones 
        //We'll increment the count with each adjacent one that make the island, and this will 
        //be the are of island 
        //We'll keep an max count 
        
        //Algorithm 
        //1. Get rows and cols of the grid 
        //2. Make a count and max count 
        //3. Make the visited array 
        //4. Run the dfs calls 
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        int max_count=0;//If there isn't any island then we have to return 0
        
        //Creating a visited array 
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                visited[i].push_back(0);
            }
        }
        //Calling the dfs
        for(int it=0;it<rows;it++){
            for(int jt=0;jt<cols;jt++){
                if(grid[it][jt]==1){
                    max_count=max(max_count, dfs(it,jt,rows,cols,grid, visited));
                }
            }
        }
        return max_count;
    }
};