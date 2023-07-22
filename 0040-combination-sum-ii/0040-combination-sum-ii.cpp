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
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i] == candidates[i-1]){
                continue;
            }
            current.push_back(candidates[i]);
            solve(candidates, i+1 , total + candidates[i], target, result, current);
            current.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, 0, target, result, current);
        return result;
    }
};