class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>current;
        sort(nums.begin(), nums.end()); //So that that duplicates elements are adjacent 
        backtrack(nums, result, current, 0);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>> &result, vector<int> &current,
                  int source){
        result.push_back(current);
        
        for(int i=source;i<nums.size();i++){
            //Condition for duplicates
            if(i>source && nums[i]==nums[i-1])
                continue;
            
            current.push_back(nums[i]);
            backtrack(nums, result, current, i+1);
            current.pop_back();
        }
    }
};