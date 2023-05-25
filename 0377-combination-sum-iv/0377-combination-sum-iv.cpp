class Solution {
public:
    
    int solve(vector<int>&nums, int target, vector<int>&dp){
        //Base Case
        //If we reach to target 0 then we reach to the end 
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        
        if(dp[target]!=-1)
            return dp[target];
        //Traverse the array
        int ans =0;
        for(int i=0;i<nums.size();i++){
            ans = ans + solve(nums, target-nums[i], dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1, -1);
        return solve(nums, target, dp);
    }
};