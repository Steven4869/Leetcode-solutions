class Solution {
public:
    int recur1(vector<int>&nums, int idx, vector<int>&dp){
        if(idx>=nums.size()-1)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx]= max(nums[idx]+recur1(nums, idx+2, dp), recur1(nums, idx+1, dp));
    }
    int recur2(vector<int>&nums, int idx, vector<int>&dp){
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx]= max(nums[idx]+recur2(nums, idx+2, dp), recur2(nums, idx+1, dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size()+1, -1);
        vector<int>dp2(nums.size()+1, -1);
        
        //Base case
        if(nums.size()==1)
            return nums[0];
        int ans1=recur1(nums, 0, dp1);
        int ans2=recur2(nums, 1, dp2);
        
        return max(ans1, ans2);
        
    }
};