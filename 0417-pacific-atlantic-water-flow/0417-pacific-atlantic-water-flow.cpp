class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>&visited, vector<vector<int>>& heights, int prev){
        if(i<0||i>=heights.size()||j<0||j>=heights[0].size()||visited[i][j]||prev>heights[i][j])
            return;
        visited[i][j]=1;
        dfs(i-1,j,visited, heights, heights[i][j]);
        dfs(i+1,j,visited, heights, heights[i][j]);
        dfs(i,j-1,visited, heights, heights[i][j]);
        dfs(i,j+1,visited, heights, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //The approach is to go from the top,bottom rows, left,right column 
        //Travel through such nodes and get into pacific or atlantic ocean 
        // Instad of going from node we'll start from last and check if node 
        //can reach pacific/atlantic ocean or not
        //For that condition is if adjacent node is greater than previous node 
        
        //Algorithm 
        //1. Get rows and cols 
        //2. Make visited array for atlantic and pacific 
        //3. For top,bottom rows call the dfs
        //4. for left, right column call the dfs 
        //5. Make the dfs function 
        //6. Mark a 2D vector resut
        //7. For every element in the visited arrays get their position in result vector
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>>pacific(rows, vector<int>(cols,0));
        vector<vector<int>>atlantic(rows, vector<int>(cols,0));
        
        //Calling the top,bottom row 
        for(int i=0;i<cols;i++){
            dfs(0, i, pacific, heights, INT_MIN);
            dfs(rows-1, i, atlantic, heights, INT_MIN);
        }
        
        //Calling left and right column 
        for(int i=0;i<rows;i++){
            dfs(i,0, pacific, heights, INT_MIN);
            dfs(i, cols-1, atlantic, heights, INT_MIN);
        }
        
        vector<vector<int>>result;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacific[i][j]&&atlantic[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};