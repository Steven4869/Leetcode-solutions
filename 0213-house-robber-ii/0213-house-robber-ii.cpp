class Solution {
public:
    int solve(vector<int>&nums, int idx, int n){
        if(idx>=n)
            return 0;
        
        int include = nums[idx] + solve(nums, idx+2, n);
        int exclude = 0 + solve(nums, idx+1, n);
        
        return max(include, exclude);
    }
    
    int solveMemo(vector<int>&nums, int idx, int n, vector<int>&dp){
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        int include = nums[idx] + solveMemo(nums, idx+2, n, dp);
        int exclude = 0 + solveMemo(nums, idx+1, n, dp);
        return dp[idx] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        //Recursive
        // int ans1 = solve(nums, 0, n-1);
        // int ans2 = solve(nums, 1, n);
        // return max(ans1, ans2);
        
        //Memoisation 
        vector<int>dp1(n+1, -1);
        vector<int>dp2(n+1, -1);
        int ans1 = solveMemo(nums, 0, n-1, dp1);
        int ans2 = solveMemo(nums, 1, n, dp2);
        return max(ans1, ans2);
    }
};