class Solution {
public:
    int solve(vector<int>&nums, int n, int curr, int prev){
        //Base Case 
        if(curr == n)
            return 0;
        //Condition
        //If the prev is -1 or the current element is greater than the prev element then include it otherwise exclude it 
        
        int take = 0;
        
        if(prev == -1 || nums[curr]>nums[prev]){
            take = 1 + solve(nums, n, curr+1,curr);
        }
        
        int notTake = 0 + solve(nums, n, curr+1, prev);
        
        return max(take, notTake);
    }
    int solveMemo(vector<int>&nums, int n, int curr, int prev, vector<vector<int>>&dp){
        //Base Case 
        if(curr == n)
            return 0;
        
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        //Condition
        //If the prev is -1 or the current element is greater than the prev element then include it otherwise exclude it 
        
        int take = 0;
        
        if(prev == -1 || nums[curr]>nums[prev]){
            take = 1 + solveMemo(nums, n, curr+1,curr, dp);
        }
        
        int notTake = 0 + solveMemo(nums, n, curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(take, notTake);
    }
    int solveBinary(vector<int>&nums){
        int n = nums.size();
        vector<int>result;
        if(n==0)
            return 0;
        
        result.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>result.back())
                result.push_back(nums[i]);
            else{
                //find the index of the bigger element
                int index = lower_bound(result.begin(), result.end(), nums[i])-result.begin();
                result[index]=nums[i];
            }
        }
        return result.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        //Using Recursion 
        
        // int n = nums.size();
        // return solve(nums, n, 0, -1);
        
        //Using Memoisation 
        
        
        // int n = nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMemo(nums, n, 0, -1, dp);
        
        //Using Binary Search 
        return solveBinary(nums);
    }
};