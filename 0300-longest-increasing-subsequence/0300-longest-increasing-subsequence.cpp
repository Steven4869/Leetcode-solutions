class Solution {
public:
    
    int solve(vector<int>&nums, int n, int curr, int prev){
        
        //Base Case 
        if(curr == n)
            return 0;
        
        int take = 0;
        
        if(prev == -1 || nums[curr]>nums[prev])
            take = 1 + solve(nums, n, curr+1, curr);
        int notTake = 0 + solve(nums, n, curr+1, prev);
        
        return max(take, notTake);
    }
    int solveMemo(vector<int>&nums, int n, int curr, int prev, vector<vector<int>>&dp){
        //Base Case 
        if(curr == n)
            return 0;
        
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        
        int take = 0;
        if(prev == -1 || nums[curr]>nums[prev]){
            take = 1 + solveMemo(nums, n, curr+1, curr, dp);
        }
        int notTake = 0 + solveMemo(nums, n, curr+1, prev, dp);
        return dp[curr][prev+1] = max(take, notTake);
    }
    int solveBinary(vector<int>&nums, int n){
        //Base Case 
        if(n==0)
            return 0;
        
        vector<int>result;
        result.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(nums[i]>result.back())
                result.push_back(nums[i]);
            else{
                int index = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
                result[index] = nums[i];
            }
        }
        
        return result.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // We need to either include the current element or exclude it then based on it get the maximum of the calls and that's the length of LIS 
        
        // int n = nums.size();
        // return solve(nums, n, 0, -1);
        
        //Using Memoisation 
        // int n = nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMemo(nums, n, 0, -1, dp);
        
        //Using Binary Search
        int n = nums.size();
        return solveBinary(nums, n);
    }
};