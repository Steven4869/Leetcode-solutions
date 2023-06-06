class Solution {
public:
    int solve(string &word1, string word2, int i, int j){
        //Base Case;
        //If the i index reaches to word1 length then return b's length - the index j is at 
        
        if(i==word1.length())
            return word2.length()-j;
        //Similiarly do it for b 
        if(j==word2.length())
            return word1.length()-i;
        
        int ans = 0;
        //If the character matches then move ahead 
        if(word1[i]==word2[j]){
            return solve(word1, word2, i+1, j+1);
        }
        else{
            //Insert
            int insertAns = 1 + solve(word1, word2, i, j+1);
            //Delete 
            int DeleteAns = 1 + solve(word1, word2, i+1, j);
            //Replace 
            int ReplaceAns = 1 + solve(word1, word2, i+1, j+1);
            
            ans = min(insertAns, min(DeleteAns, ReplaceAns));
        }
        return ans;
    }
    
    int solveMemo(string &word1, string word2, int i, int j, vector<vector<int>>&dp){
        //Base Case;
        //If the i index reaches to word1 length then return b's length - the index j is at 
        
        if(i==word1.length())
            return word2.length()-j;
        //Similiarly do it for b 
        if(j==word2.length())
            return word1.length()-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 0;
        //If the character matches then move ahead 
        if(word1[i]==word2[j]){
            return solveMemo(word1, word2, i+1, j+1, dp);
        }
        else{
            //Insert
            int insertAns = 1 + solveMemo(word1, word2, i, j+1, dp);
            //Delete 
            int DeleteAns = 1 + solveMemo(word1, word2, i+1, j, dp);
            //Replace 
            int ReplaceAns = 1 + solveMemo(word1, word2, i+1, j+1, dp);
            
            ans = min(insertAns, min(DeleteAns, ReplaceAns));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(501, vector<int>(501, -1));
        return solveMemo(word1, word2, 0, 0, dp);
    }
};