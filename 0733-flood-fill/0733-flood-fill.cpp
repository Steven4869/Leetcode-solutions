class Solution {
public:
    
    void dfs(vector<vector<int>>&image, int sr, int sc, int rows, int cols, int color, int source){
        //Boundary Conditions 
        if(sr<0||sr>=rows||sc<0||sc>=cols){
            return;
        }
        else if(source!=image[sr][sc]){
            return;
        }
        image[sr][sc] = color;
        
        //Then Call DFS in 4 directions 
        dfs(image, sr-1, sc, rows, cols, color, source);
        dfs(image, sr+1, sc, rows, cols, color, source);
        dfs(image, sr, sc-1, rows, cols, color, source);
        dfs(image, sr, sc+1, rows, cols, color, source);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)    {
       //Get the rows and columns 
        int rows = image.size();
        int columns = image[0].size();
        
        //Get the source 
        int source = image[sr][sc];
        
        if(source!=color){
            dfs(image, sr, sc, rows, columns, color, source);
        }
        return image;
    }
};