class Solution {
public:
    void solve(int n, int k, vector<int>&current, vector<vector<int>> &result, int index){
        
        if(k==0){
            result.push_back(current);
            return;
        }
        for(int i=index;i<=n;i++){
            current.push_back(i);
            solve(n,k-1,current,result,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>current;
        solve(n,k,current,result,1);
        return result;
    }
};