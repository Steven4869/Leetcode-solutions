class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int source, int rows, int cols){
        //Base Condition 
        if(sr<0 || sc <0 || sr>=rows || sc>=cols || image[sr][sc]!=source)
            return;
        image[sr][sc]=color;
        dfs(image, sr-1, sc, color, source, rows, cols);
        dfs(image, sr+1, sc, color, source, rows, cols);
        dfs(image, sr, sc-1, color, source, rows, cols);
        dfs(image, sr, sc+1, color, source, rows, cols);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc];
        
        if(source != color){
            dfs(image, sr, sc, color, source, rows, cols);
        }
        return image;
    }
};