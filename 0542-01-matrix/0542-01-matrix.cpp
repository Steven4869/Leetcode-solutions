class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        if(rows==0)
            return mat;
        queue<pair<int,int>>q;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        vector<pair<int,int>>directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto dir:directions){
                int newX = x + dir.first;
                int newY = y + dir.second;
                
                if(newX>=0 && newY>=0 && newX<rows && newY<cols && 
                  mat[newX][newY]>mat[x][y]+1){
                    mat[newX][newY]=mat[x][y]+1;
                    q.push({newX, newY});
                }
            }
        }
        return mat;
    }
};