class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val){
        for(int i=0;i<9;i++){
            if(board[row][i] == val)
                return false;
            if(board[i][col] == val)
                return false;
        }
        int subgridStartRow = (row / 3) * 3;
        int subgridStartCol = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[subgridStartRow + i][subgridStartCol + j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool sudokuSolver(vector<vector<char>>&board){
        int n = board[0].size();
        
        for(int row = 0;row<n;row++){
            for(int col=0;col<n;col++){
                //Cell is empty
                if(board[row][col] == '.'){
                    for(char val='1';val<='9';val++){
                        if(isSafe(row, col, board, val)){
                            board[row][col] = val;
                            if(sudokuSolver(board))
                                return true;
                            board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }
};