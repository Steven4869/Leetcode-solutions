class Solution {
public:
    bool isPalindrome(string s){
        int left =0, right = s.length()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, int index, vector<vector<string>>&result,
              vector<string>&current){
        if(index == s.length()){
            result.push_back(current);
            return;
        }
        
        for(int i=index;i<s.length();i++){
            string substring = s.substr(index, i-index+1);
            if(isPalindrome(substring)){
                current.push_back(substring);
                solve(s, i+1, result, current);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>current;
        solve(s, 0, result, current);
        return result;
    }
};