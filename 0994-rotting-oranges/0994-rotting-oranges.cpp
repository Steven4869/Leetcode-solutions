class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //It's a multisource BFS problem on grid 
        //Approach is to keep the track of fresh oranges 
        //Put the rotten oranges into queue 
        //Run the loop until the queue is empty or fresh oranges are finished 
        //MArk them in the grid, with each marking increment the time 
        //Time is the number of loops it went through 
        
        //Approach 
        //1. Get rows and cols 
        int rows = grid.size();
        int cols = grid[0].size();
        
        int freshOranges=0;
        
        //2. Make up a queue 
        queue<pair<int,int>>q;
        
        //3. Run a loop and get the count of Fresh Oranges, push all the rotten ones into queue 
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1)
                    freshOranges++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        // 4. Get a time variable and direction array 
        int time =0;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        //5. Perform BFSfor every rotten orange into queue 
        
        while(!q.empty()&&freshOranges !=0){
            int size=q.size();
            for(int i=0;i<size;i++){
            pair<int,int>curr=q.front();
            
            q.pop();
            
            //For all the four directions 
            for(int i=0;i<4;i++){
                int new_r = curr.first + dir[i][0];
                int new_c = curr.second + dir[i][1];
                //Put up a boundary condition 
                if(new_r>=0&&new_r<rows&&new_c>=0&&new_c<cols&&grid[new_r][new_c]==1){
                    grid[new_r][new_c]=2;
                    q.push({new_r,new_c});
                    freshOranges--;
                }
            }
            }
            time++;
        }
        return freshOranges == 0?time:-1;
        
    }
};