class Solution {
public:
    void generateSubset(vector<int>&nums, int start, vector<int>&current,
                       vector<vector<int>>&result){
        if(start == nums.size()){
            result.push_back(current);
            return;
        }
        current.push_back(nums[start]);
        generateSubset(nums, start+1, current, result);
        current.pop_back();
        generateSubset(nums, start+1, current, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>current;
        generateSubset(nums, 0, current, result);
        return result;
    }
};