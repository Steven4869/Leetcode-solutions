class Solution {
public:
    
    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>&dp){
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(i==n1 || j==n2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(nums1[i]==nums2[j]){
            return dp[i][j] = 1 + dfs(nums1, nums2, i+1, j+1, dp);
        }
        else{
            return dp[i][j] = max(dfs(nums1, nums2, i, j+1, dp),dfs(nums1, nums2, i+1, j, dp));
        }
        
        return dp[i][j];
                
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1, -1));
        return dfs(nums1, nums2, 0, 0, dp);
        
    }
    
};