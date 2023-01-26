class Solution {
public:
    int recur(vector<int>& nums, int idx, vector<int>&dp){
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx]=max(nums[idx]+recur(nums, idx+2, dp), recur(nums, idx+1, dp));
        //It takes O(2^N) time
        //we have to reduce the time with dp memo 
    }
    int rob(vector<int>& nums) {
        //This is a simple 1-D DP Problem 
        //Find the recurrence relation 
        //Robber can do two jobs: he'll rob the house or will not rob the house ]
        //If he chooses the first house the amount will be money from the (i-2)th house+
        //money from the ith house 
        //Otherwise rob from the money of (i-1)th house 
        vector<int>dp(nums.size()+1, -1);
        return recur(nums, 0, dp);
    }
};