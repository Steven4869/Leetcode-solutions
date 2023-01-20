class Solution {
public:
//     void recur(vector<int>&nums, int i, bool &ans){
//         if(ans == true){
//             return;
//         }
//         if(i==nums.size()-1){
//             ans = true;
//             return;
//         }
        
//         //recursive function 
//         for(int j=1;j<=nums[i]&&j+i<nums.size();j++){
//             recur(nums, i+j, ans);
//         }
//         //TC : O(N^N)
//         //We can use DP to minimise the TC
//     }
    bool canJump(vector<int>& nums) {
        //Brute Force Method 
        //Get all the jump at once and check every jump 
        //We'll follow recursion 
        
        // bool ans = false;
        // recur(nums, 0, ans);
        // return ans;
        
        //DP
        vector<bool>dp(nums.size(), false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==true){
                for(int j=1;j<=nums[i]&&j+i<nums.size();j++){
                    dp[i+j]=true;
                    if(i+j==nums.size()-1)
                        return true;
                }
            }
        }
        return dp[nums.size()-1];
    }
};