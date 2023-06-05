class Solution {
public:
    long long solve(string &text1, string &text2, int i, int j, vector<vector<int>>&dp){
        //Base Case 
        //If i or j reaches to the size of the string then return 0
        
        if(i==text1.size()||j==text2.size()){
            return 0;
        }
        long long ans =0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        //If the text1's ith matches with text2's jth index
        if(text1[i]==text2[j]){
            ans = 1+solve(text1, text2, i+1, j+1, dp);
        }
        else{
            //We have to check for the (i+1,j) and(i,j+1) then take out the max out of it
            ans=max(solve(text1, text2, i, j+1, dp), solve(text1, text2, i+1, j, dp));
        }
        return dp[i][j]=ans;
        
        
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(1001, vector<int>(1001, -1));
        string y = s;
        reverse(y.begin(), y.end());
        return solve(s, y, 0, 0, dp);
    }
};