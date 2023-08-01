class Solution {
public:
    
    void solve(vector<int>&nums, int index, int total, int k, int target, vector<vector<int>>&result, vector<int>&current){
        if(total == target && current.size() == k){
            result.push_back(current);
            return;
        }
        
        if(total>target || index >= nums.size() || current.size() >= k)
            return;
        
        current.push_back(nums[index]);
        solve(nums, index+1, total+nums[index], k, target, result, current);
        current.pop_back();
        solve(nums, index+1, total, k, target, result, current);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        
        vector<vector<int>>result;
        vector<int>current;
        
        solve(nums, 0, 0, k, n, result, current);
        
        return result;
    }
};