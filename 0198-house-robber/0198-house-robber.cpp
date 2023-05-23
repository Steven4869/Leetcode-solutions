class Solution {
public:
    //Based on the operation, that if we include then raise the index by 2 otherwise if we are 
    //excluding then raise the index by 1
    
    int solve(vector<int>&nums, int idx, vector<int>&dp){
        //Base Case 
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int include = nums[idx]+solve(nums, idx+2, dp);
        int exclude = 0 + solve(nums, idx+1, dp);
        int ans = max(include, exclude);
        return dp[idx] = ans;
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};