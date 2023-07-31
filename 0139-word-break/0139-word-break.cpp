class Solution {
public:
    bool solve(string s, int start, unordered_set<string>&dict, vector<int>&dp){
        if(start == s.length())
            return true;
        
        if(dp[start] != -1)
            return dp[start];
        
        for(int end = start+1;end<=s.length();end++){
            if(dict.count(s.substr(start, end-start)) && solve(s, end, dict,dp)){
                dp[start] = 1;
                return true;
            }
        }
        dp[start]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        vector<int>dp(s.length()+1, -1);
        return solve(s, 0, dict, dp);
    }
};