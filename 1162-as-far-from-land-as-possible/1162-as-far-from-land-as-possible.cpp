class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //It's a Multisource BFS Problem 
        //We'll increment the distance with each bfs calling for the grid 
        //The distance obtained once every grid becomes 1 will be the answer 
        
        //Approach 
        //1. Get rows and cols 
        int rows = grid.size();
        int cols = grid[0].size();
        
        //2. Make up a queue 
        queue<pair<int,int>>q;
        
        //3. Push all the coordinates of land into queue 
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        //Base Case
        if(q.size()==rows*cols)
            return -1;
        
        
        //4. Make a direction array and diatnce to 0
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        
        int distance =0;
        
        //5. Perform BFS for each island 
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                pair<int,int>curr=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int new_r=curr.first+dir[i][0];
                    int new_c=curr.second+dir[i][1];
                    
                    if(new_r>=0&&new_r<rows&&new_c>=0&&new_c<cols&&grid[new_r][new_c]==0){
                        //Push it into queue 
                        q.push({new_r,new_c});
                        //Make the water cell as island
                        grid[new_r][new_c]=1;
                    }
                }
                
            }
            distance++;
        }
        return distance-1;
        
    }
};