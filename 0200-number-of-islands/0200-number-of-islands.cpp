class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //Using BFS
        //Basic Apporach 
        //1. Create a visited array 
        //2. Traverse through each row and column and check whether it's visited or not
        //3. If visited check whether it's 1 in grid
        //4. If it's marked then insert into queue
        
        int rows= grid.size();
        int cols= grid[0].size();
        int count=0;
        // Creating a 2D visited array 
        int visited[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                visited[i][j]=0;
            }
        }
        
        //Traversing through grid 
        for(int it=0;it<rows;it++){
            for(int jt=0;jt<cols;jt++){
                //Checking if it's visited and grid being marked as 1
                if(!visited[it][jt]&&grid[it][jt]=='1'){
                    //Mark it as visited 
                    visited[it][jt]='1';
                    //Perform BFS
                    queue<pair<int,int>>q;
                    q.push({it,jt});
                    count++;
                    
                    while(!q.empty()){
                        int i=q.front().first;
                        int j=q.front().second;
                        //Checking for all four directions
                        //Top
                        if(j-1>=0){
                            if(!visited[i][j-1]){
                                visited[i][j-1]='1';
                                if(grid[i][j-1]=='1'){
                                    q.push({i,j-1});
                                    visited[i][j-1]='1';
                                }
                            }
                        }
                        //Bottom 
                        if(j+1<cols){
                            if(!visited[i][j+1]){
                                
                                if(grid[i][j+1]=='1'){
                                    q.push({i,j+1});
                                    visited[i][j+1]='1';
                                }
                            }
                        }
                        //Left
                        if(i-1>=0){
                            if(!visited[i-1][j]){
                                
                                if(grid[i-1][j]=='1'){
                                    q.push({i-1,j});
                                    visited[i-1][j]='1';
                                }
                            }
                        }
                        //Right
                        if(i+1<rows){
                            if(!visited[i+1][j]){
                                
                                if(grid[i+1][j]=='1'){
                                    q.push({i+1,j});
                                    visited[i+1][j]='1';
                                }
                            }
                        }
                        q.pop();
                    }

                }
            }
        }
        return count;
    }
};