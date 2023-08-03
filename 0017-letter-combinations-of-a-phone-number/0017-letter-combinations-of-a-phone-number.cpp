class Solution {
public:
    
    void solve(string &digits, int index, vector<string>&result, string &current, vector<string>&mp){
        
        if(index == digits.size()){
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        
        for(char c:mp[digit]){
            current.push_back(c);
            solve(digits, index+1, result, current, mp);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        
        vector<string>result;
        
        vector<string>mp = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        
        string current = "";
        
        solve(digits, 0, result, current, mp);
        
        return result;
    }
};