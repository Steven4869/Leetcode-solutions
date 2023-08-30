class Solution {
public:
    bool solve(vector<int>&nums, int idx, vector<int>&dp){
        int n = nums.size();
        if(idx == n-1)
            return true;
        if(idx>=n)
            return false;
        if(nums[idx] == 0)
            return false;
        if(dp[idx]!=-1)
            return dp[idx];
        for(int j=1;j<=nums[idx];j++){
            if(solve(nums, idx+j, dp)){
                dp[idx] = 1;
                return true;
            }            
        }
        dp[idx] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};