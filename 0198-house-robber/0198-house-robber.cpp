class Solution {
public:
    
    int solveRecursive(vector<int>& nums, int idx){
        if(idx>=nums.size())
            return 0;
        
        int include = nums[idx] + solveRecursive(nums, idx+2);
        int exclude = 0 + solveRecursive(nums, idx+1);
        
        int ans = max(include, exclude);
        
        return ans;
        
        //TLE, TC:O(2^N) SC: O(1)
    }
    
    int solveMemo(vector<int>&nums, int idx, vector<int>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int include = nums[idx] + solveMemo(nums, idx+2, dp);
        int exclude = 0 + solveMemo(nums, idx+1, dp);
        
        int ans = max(include, exclude);
        
        return dp[idx] = ans;
        
        // TC: O(N) SC: O(N)

    }
    
    int solveTabulation(vector<int>&nums){
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp(n);
        
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
        return dp[n-1];
        
        // TC: O(N) SC: O(N)
    }
    
    int solveConstant(vector<int>&nums){
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        int prevPrev = nums[0];
        int prev = max(nums[0], nums[1]);
        int curr = prev;
        
        for(int i=2;i<n;i++){
            curr = max(prev, nums[i] + prevPrev);
            prevPrev = prev;
            prev = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
       
        //Recursive 
        // return solveRecursive(nums, 0);
        
        //Memoisation
        // int n = nums.size();
        // vector<int>dp(n+1, -1);
        // return solveMemo(nums, 0, dp);
        
        //Tabulation 
        // return solveTabulation(nums);
        
        //Constant Space
        return solveConstant(nums);
    }
};