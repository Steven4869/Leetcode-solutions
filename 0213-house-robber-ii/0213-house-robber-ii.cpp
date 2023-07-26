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
    
    int solveTabulation(vector<int>&nums){
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0], nums[1]);
        vector<int>dp1(n);
        dp1[0]=nums[0];
        dp1[1]=max(nums[0], nums[1]);
        
        for(int i=2;i<n-1;i++){
            dp1[i] = max(dp1[i-1], nums[i] + dp1[i-2]);
        }
        
        vector<int>dp2(n);
        dp2[1]=nums[1];
        dp2[2]=max(nums[1], nums[2]);
        
        for(int i=3;i<n;i++){
            dp2[i] = max(dp2[i-1], nums[i] + dp2[i-2]);
        }
        
        return max(dp1[n-2], dp2[n-1]);
        
        
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
        
        // vector<int>dp1(n+1, -1);
        // vector<int>dp2(n+1, -1);
        // int ans1 = solveMemo(nums, 0, n-1, dp1);
        // int ans2 = solveMemo(nums, 1, n, dp2);
        // return max(ans1, ans2);
        
        // Tabulation
        
        return solveTabulation(nums);
        
        
    }
};