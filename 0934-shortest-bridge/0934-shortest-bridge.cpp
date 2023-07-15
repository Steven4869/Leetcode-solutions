class Solution {
public:
    void dfs(vector<vector<int>>&grid, int i, int j, queue<pair<int,int>>&q){
        //Base conditions 
        int rows = grid.size();
        int cols = grid[0].size();
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j] !=1)
            return;
        grid[i][j]=2;
        q.push({i,j});
        dfs(grid, i+1, j, q);
        dfs(grid, i-1, j, q);
        dfs(grid, i, j+1, q);
        dfs(grid, i, j-1, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int,int>>q;
        
        bool found = false;
        
        //Identifying the island through DFS
        for(int i=0;i<rows;i++){
            if(found)
                break;
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, q);
                    found = true;
                    break;
                }
            }
        }
        
        //Performing Multisoucre BFS on the island and noting the 
        //times to reach the target
        
        int steps = 0;
        vector<pair<int, int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(auto dir:directions){
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    
                    if(newX<0 || newX>=rows || newY<0 || newY>=cols 
                      || grid[newX][newY] == 2)
                        continue;
                    if(grid[newX][newY]==1)
                        return steps;
                    grid[newX][newY]=2;
                    q.push({newX, newY});
                }
            }
            steps++;
        }
        return -1;
    }
};