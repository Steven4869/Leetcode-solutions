class Solution {
public:
    
    void dfs(int i, int j, int rows, int cols, vector<vector<char>>& grid, vector<vector<int>> &visited){
        if(i<0||j<0||i>=rows||j>=cols||visited[i][j]||grid[i][j]=='0')
            return;
        //Mark the visited 
        visited[i][j]=1;
        dfs(i-1,j,rows,cols,grid,visited);
        dfs(i+1,j,rows,cols,grid,visited);
        dfs(i,j-1,rows,cols,grid,visited);
        dfs(i,j+1,rows,cols,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        //Using DFS 
        //Approach 
        //1. Get the rows and columns 
        //2. make up a visited array 
        //3. Run the dfs for all four directions 
        
        int rows = grid.size();
        int cols = grid[0].size();
        //Creating visited array 
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                visited[i].push_back(0);
            }
        }
        int count=0;
        
        for(int it=0;it<rows;it++){
            for(int jt=0;jt<cols;jt++){
                if(!visited[it][jt]&&grid[it][jt]=='1'){
                    //Call the recursvie function 
                    dfs(it,jt,rows,cols,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};