class Solution {
public:
    
    void solve(vector<int>& candidates, int index, int total, int target, vector<vector<int>>&result, vector<int>&current){
        
        //Base Case 
        if(total == target){
            result.push_back(current);
            return;
        }
        
        if(total>target || index>=candidates.size())
            return;
        
        //Push the index element into current
        current.push_back(candidates[index]);
        solve(candidates, index, total+candidates[index], target, result, current);
        current.pop_back();
        solve(candidates, index+1, total, target, result, current);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>result;
        vector<int>current;
        
        solve(candidates, 0, 0, target, result, current);
        
        return result;
        
    }
};