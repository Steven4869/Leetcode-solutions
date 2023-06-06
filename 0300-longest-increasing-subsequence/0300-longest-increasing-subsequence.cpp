class Solution {
public:
    int solve(vector<int>&nums, int curr, int prev){
        //The current is initialised to 0 whereas prev as -1 to include the first element of array
        
        //Base Case 
        //If the current index goes out of the index 
        if(curr==nums.size())
            return 0;
        
        //Case for Include 
        int take =0;
        if(prev ==-1 || nums[prev]<nums[curr]){
            take = 1 + solve(nums, curr+1, curr);
        }
        int notTake = 0 + solve(nums, curr+1, prev);
        //Take the maximum of Take and notTake
        return max(take, notTake);
        
    }
    int solveMemo(vector<int>&nums, int curr, int prev, vector<vector<int>>&dp){
        //The current is initialised to 0 whereas prev as -1 to include the first element of array
        
        //Base Case 
        //If the current index goes out of the index 
        if(curr==nums.size())
            return 0;
        
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        //Case for Include 
        int take =0;
        if(prev ==-1 || nums[prev]<nums[curr]){
            take = 1 + solveMemo(nums, curr+1, curr, dp);
        }
        int notTake = 0 + solveMemo(nums, curr+1, prev, dp);
        //Take the maximum of Take and notTake
        //Take prev+1 because we are starting from -1
        return dp[curr][prev+1]=max(take, notTake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        //This Question is similar to 0/1 Knapsack of including and excluding 
        //We will traverse the array and would go for two cases of including and excluding 
        //Condition of including, previous element has to be smaller than the upcoming element 
        // return solve(nums, 0, -1);
        
        //Using Memoisation
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return solveMemo(nums, 0, -1, dp);
    }
};