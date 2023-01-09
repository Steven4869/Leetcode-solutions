class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int rows, int cols, int color, int source){
        //Base Boundary Conditions
        if(sr<0||sr>=rows||sc<0||sc>=cols)
            return;
        else if(image[sr][sc]!=source)
            return;
        //Make the selected node to the color
        image[sr][sc]=color;
        //Calling 4 directional DFS Calls 
        dfs(image, sr-1, sc, rows, cols, color, source);//Top
        dfs(image, sr+1, sc, rows, cols, color, source);//Bottom 
        dfs(image, sr, sc-1, rows, cols, color, source);//Left
        dfs(image, sr, sc+1, rows, cols, color, source);//Right
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //The idea is that we have to get the source node from given sr,sc values
        //Then change the value of node to the color 
        //Then recurively call the all 4 directions and check if the node is equal to source nodes
        //If they are equal then change it to color 
        //Basic DFS Traversal is followed 
        
        //Get rows and cols of the image 
        int rows = image.size();
        int cols = image[0].size();
        //Get the source node 
        int source = image[sr][sc];
        //If the source node is not equal to the color then call the recursive function 
        if(source!=color){
            dfs(image, sr, sc, rows, cols, color, source);
        }
        //Returning the image grid after making changes 
        return image;
    }
};