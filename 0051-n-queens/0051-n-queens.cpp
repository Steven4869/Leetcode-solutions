class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        int x = 0;
        while(x<row){
            if(board[x][col] == 'Q')
                return false;
            x++;
        }
        x = row;
        int y = col;
        //Upper Diagonal
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }
        
        //Lower Diagonal
        x = row;
        y = col;
        
        while(x>=0 && y<n){
            if(board[x][y] == 'Q')
                return false;
            x--;
            y++;
        }
        return true;
        
    }
    void solveNQueen(vector<vector<string>>&result, vector<string>&board,
                    int row, int n){
        if(row == n){
            result.push_back(board);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solveNQueen(result, board, row+1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n, string(n, '.'));
        
        solveNQueen(result, board, 0, n);
        return result;
    }
};