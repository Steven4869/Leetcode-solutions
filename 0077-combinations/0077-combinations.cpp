class Solution {
public:
    void solve(vector<vector<int>>&result, vector<int>&combination, 
              int n, int k, int index){
        if(k==0){
            result.push_back(combination);
            return;
        }
        for(int i=index;i<=n;i++){
            combination.push_back(i);
            solve(result, combination, n, k-1, i+1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>combination;
        solve(result, combination, n, k, 1);
        return result;
    }
};