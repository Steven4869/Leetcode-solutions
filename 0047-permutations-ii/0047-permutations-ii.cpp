class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        unordered_map<int, int> count; // Maintain count of elements used
        
        for (int num : nums) {
            count[num]++;
        }
        
        backtrack(nums, current, result, count);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, unordered_map<int, int>& count) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (const auto& entry : count) {
            int num = entry.first;
            int freq = entry.second;
            
            if (freq > 0) {
                current.push_back(num);
                count[num]--;
                backtrack(nums, current, result, count);
                current.pop_back();
                count[num]++;
            }
        }
    }
};
