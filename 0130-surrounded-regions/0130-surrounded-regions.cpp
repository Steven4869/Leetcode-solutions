class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!='O')
            return;
        board[i][j]='1';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        //This problem is similar to Number of islands 
        //We'll check the boundary of regiond if they have O then cahnge it and 
        //its adjacent Os to 1 
        //Run the dfs for evry boundary O found 
        //Mark it as 1
        //Make all non 1s as X and others as O
        
        int rows = board.size();
        int cols = board[0].size();
        //Base condition 
        if(rows==0||cols==0)
            return;
        //Checking any boundaru O and making a dfs call on it 
        for(int i=0;i<cols;i++){
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[rows-1][i]=='O')
                dfs(board,rows-1,i);
        }
        for(int i=1;i<rows-1;i++){
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][cols-1]=='O')
                dfs(board,i,cols-1);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]!='1')
                    board[i][j]='X';
                if(board[i][j]=='1')
                    board[i][j]='O';
            }
        }
        // return board;
    }
};