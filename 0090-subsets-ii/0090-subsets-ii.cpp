class Solution {
public:
    void generateSubset(vector<int>&nums, int start, vector<int>&current,
                       vector<vector<int>>&result){
        result.push_back(current);
        
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i] == nums[i-1])
                continue;
            
            current.push_back(nums[i]);
            generateSubset(nums, i+1, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        vector<int>current;
        generateSubset(nums, 0, current, result);
        return result;
    }
};