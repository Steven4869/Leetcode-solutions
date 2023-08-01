class Solution {
public:
    
    void solve(vector<int>& candidates, int index, int total, int target, vector<int> &current, vector<vector<int>> &result){
        
        if(total == target){
            result.push_back(current);
            return;
        }
        
        if(total>target || index>=candidates.size())
            return;
        
        for(int i=index;i<candidates.size();i++){
            
            //Removing the duplicates 
            if(i>index && candidates[i] == candidates[i-1])
                continue;
            
            current.push_back(candidates[i]);
            solve(candidates, i+1, total + candidates[i], target, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current;
        
        sort(candidates.begin(), candidates.end());
        
        solve(candidates, 0, 0, target, current, result);
        
        return result;
    }
};