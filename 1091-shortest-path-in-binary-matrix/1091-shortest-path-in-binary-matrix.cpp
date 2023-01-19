class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //It's a Multisource BFS question 
        
        //Algorithm 
        //1. Get rows and cols 
        int rows = grid.size();
        int cols = grid[0].size();
        
        //Base Case 
        if(grid.empty()||grid[0][0]!=0){
            return -1;
        }
        
        if(grid[0][0]==0&&rows==1&&cols==1){
            return 1;
        }
        //2. Make a queue 
        queue<pair<int,int>>q;
        //Insert the frst two element 
        q.push(make_pair(0,0));
        //Make the first element in grid to be 1
        grid[0][0]=1;
        //3. Make the direction array and ressult
        //We are going with 8 dirctions here 
        int dir[8][2]={{-1,0},{1,0},{-1,1},{-1,-1},{0,-1},{0,1},{1,-1},{1,1}};
        int result =0;
        
        //4.Run the bfs for every 0 element 
        while(!q.empty()){
            int size = q.size();
            result++;
            for(int i=0;i<size;i++){
                pair<int,int>curr=q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int new_r=curr.first+dir[i][0];
                    int new_c=curr.second+dir[i][1];
                    //Boundary conditions 
                    if(new_r>=0&&new_r<rows&&new_c>=0&&new_c<cols&&grid[new_r][new_c]==0){
                        if(new_r==rows-1&&new_c==cols-1){
                            return result+1;
                        }
                        q.push(make_pair(new_r,new_c));
                        grid[new_r][new_c]=1;
                    }
                }
            }
            
        }
        return -1;
    }
};