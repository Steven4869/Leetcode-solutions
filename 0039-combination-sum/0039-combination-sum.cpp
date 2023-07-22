class Solution {
public:
    void solve(vector<int>& candidates, int start, int total, int &target, 
               vector<vector<int>>& result, vector<int> &current){
        if(total == target){
            result.push_back(current);
            return;
        }
        if(total>target || start>=candidates.size())
            return;
        
        current.push_back(candidates[start]);
        solve(candidates, start, total + candidates[start], target, result, current);
        current.pop_back();
        solve(candidates, start + 1, total, target,  result, current);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current;
        
        solve(candidates, 0, 0, target, result, current);
        return result;
    }
};