class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges=0;
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int time = 0;
        
        while(!q.empty() && freshOranges!=0){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(auto dir:directions){
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if(newX>=0 && newY>=0 && newX<rows && newY<cols 
                      && grid[newX][newY] == 1){
                        grid[newX][newY]=2;
                        q.push({newX, newY});
                        freshOranges--;
                    }
                }
            }
            time++;
        }
        if(freshOranges != 0){
            return -1;
        }
        return time;
    }
};