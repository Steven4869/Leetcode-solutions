class Solution {
public:
    
    int solve(string s, string t, int i, int j){
        if(j==t.length())
            return 1;
        if(i == s.length())
            return 0;
        
        int count = 0;
        
        if(s[i] == t[j])
            count = count + solve(s,t, i+1, j+1);
        
        count = count + solve(s,t,i+1,j);
        
        return count;
    }
    int solveMemo(string s, string t, int i, int j, vector<vector<int>>&dp){
        if(j==t.length())
            return 1;
        if(i == s.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int count = 0;
        
        if(s[i] == t[j])
            count = count + solveMemo(s,t, i+1, j+1, dp);
        
        count = count + solveMemo(s,t,i+1,j, dp);
        
        return dp[i][j] = count;
    }
    int numDistinct(string s, string t) {
        
        //Recursion
        // return solve(s,t,0,0);
        
        //Memoisation 
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, -1));
        return solveMemo(s,t,0,0,dp);
    
    }
};