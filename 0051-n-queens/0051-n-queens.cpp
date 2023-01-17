class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //Problem is based on Backtracking 
        //What we will follow is that we'll check both diagonals and columns of the Queen 
        //Then we'll create a array where we'll store the position as Q
        
        //Algortihm 
        //1. Make the array for result and board consisting of dots 
        vector<vector<string>>result;
        vector<string>board(n, string(n, '.'));
        
        //2. Make the set for Positive Dialginal, Negative Diagonal and Column 
        unordered_set<int> positiveDiagonal, negativeDiagonal, column;
        
        //3. Call the backtrack function 
        int len = n;
        backtrack(0, result, board, positiveDiagonal, negativeDiagonal, column, len);
        
        //4. Return the result
        return result;
    }
    
    //Making the backtrack function 
    void backtrack(int rows, vector<vector<string>> &result, vector<string> &board, 
                  unordered_set<int> &positiveDiagonal, unordered_set<int>                                      &negativeDiagonal, unordered_set<int> &column, int &len){
        //5. If the row reaches the end then we have got the solution 
        if(rows == len){
            result.push_back(board);
            return;
        }
        //6. For every column check the validity of the Queen 
        for(int cols=0;cols<len;cols++){
            if(isValid(rows, cols, positiveDiagonal, negativeDiagonal, column)){
                //Then do the backtrack
                board[rows][cols] = 'Q';
                positiveDiagonal.insert(rows+cols);
                negativeDiagonal.insert(rows-cols);
                column.insert(cols);
                
                backtrack(rows+1, result, board, positiveDiagonal, negativeDiagonal,                                    column,len);
                
                board[rows][cols] = '.';
                positiveDiagonal.erase(rows+cols);
                negativeDiagonal.erase(rows-cols);
                column.erase(cols);
            }
        }
    }
    //Making the isValid function 
    
    bool isValid(int rows, int cols, unordered_set<int> &positiveDiagonal,                                  unordered_set<int>&negativeDiagonal, unordered_set<int> &column){
        bool isPosDiagonal = (positiveDiagonal.find(rows+cols) == positiveDiagonal.end());
        bool isNegDiagonal = (negativeDiagonal.find(rows-cols) == negativeDiagonal.end());
        bool isColumn      = (column.find(cols) == column.end());
        return isPosDiagonal&&isNegDiagonal&&isColumn;
    }
};