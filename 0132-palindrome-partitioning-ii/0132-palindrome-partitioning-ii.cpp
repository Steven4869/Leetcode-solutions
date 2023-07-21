class Solution {
public:
    int solve(int start, int end, vector<vector<bool>>&isPalindrome,
             vector<vector<int>>&memo){
        if(start == end || isPalindrome[start][end])
            return 0;
        
        if(memo[start][end]!=-1)
            return memo[start][end];
        
        int minCuts = INT_MAX;
        for(int i=start;i<end;i++){
            if(isPalindrome[start][i]){
                minCuts = min(minCuts, solve(i+1, end, isPalindrome, memo)+1);
            }
        }
        
        return memo[start][end]=minCuts;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>>memo(n, vector<int>(n, -1));
        vector<vector<bool>>isPalindrome(n, vector<bool>(n, false));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j] && (j-i<=1 || isPalindrome[i+1][j-1])){
                    isPalindrome[i][j]=true;
                }
            }
        }
        
        return solve(0, n-1, isPalindrome, memo);
    }
};