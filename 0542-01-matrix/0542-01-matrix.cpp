class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         //Important Problem to understand multisource BFS
//         //Brute Force 
//         //1. Make a distance vector for each element then initalise it to INT_MAX 
//         //2. Iterate over the matrix, if cell is 0 then distance is 0
//         //3. Else for every 1 cell iterate over entire matrix 
//         //4. If the cell is 0 then caluclate the distance 
        
//         //Getting rows and cols 
//         int rows = mat.size();
//         int cols = mat[0].size();
        
//         //If there are no rows, return the matrix Edge case 
//         if(rows == 0)
//             return mat;
        
//         //Intialise a distance vector 
//         vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
//         //Traversing the matrix 
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(mat[i][j]==0)
//                     dist[i][j]=0;
//                 else{
//                     for(int k=0;k<rows;k++){
//                         for(int l=0;l<cols;l++){
//                             if(mat[k][l]==0){
//                                 int dist_01 = abs(k-i) + abs(l-j);
//                                 dist[i][j] = min(dist[i][j],abs(k-i)+abs(l-j));

//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return dist;
//         //TC:O(RXC)^2
        
        //Better Apporach
        //Go with BFS 
        //Approach 
        //1. Get rows and cols 
        //2. Create  distance array 
        //3. Make all the 0s into distance array as 0 and push all of them into queues 
        //4. Create a direction array to check all four directions of the node 
        //5. Pop it from queue to some variable 
        //6. Get new rows and col as element of the pop stored variable and direction array 
        //7. If it's greater then store into distance array 
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        //Base condition 
        if(rows==0)
            return mat;
        
        queue<pair<int, int>>q;
        //Distance array 
        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        //Perform BFS
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int new_r = curr.first+dir[i][0];
                int new_c = curr.second+dir[i][1];
                
                if(new_r>=0&&new_c>=0&&new_r<rows&&new_c<cols){
                    if(dist[new_r][new_c]>dist[curr.first][curr.second]+1){
                        dist[new_r][new_c]=dist[curr.first][curr.second]+1;
                        q.push({new_r, new_c});
                    }
                }
            }
        }
        return dist;
    }
};