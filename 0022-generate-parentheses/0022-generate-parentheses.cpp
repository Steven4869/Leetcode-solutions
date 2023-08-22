class Solution {
public:
    void solve(string s, int open, int close, vector<string>&result){
        if(open ==0 && close == 0){
            result.push_back(s);
            return;
        }
        if(open>0)
            solve(s+'(', open-1, close, result);
        if(open<close)
            solve(s+')', open, close-1, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve("", n, n, result);
        return result;
    }
};