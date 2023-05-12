class Solution {
public:
    
    long long dfs(vector<vector<int>>&questions, int i, vector<long long>&dp){
        //Boundary conditions 
        if(i>=questions.size()){
            return 0;
        }
        long long points = questions[i][0];
        long long skip = questions[i][1];
        
        //solve it or skip it
        long long result;
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i] = max(points + (dfs(questions, i+skip+1, dp)), dfs(questions, i+1, dp));
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(), -1);
        return dfs(questions, 0, dp);
    }
};