class Solution {
public:
    
    bool isPalindrome(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s, int index, vector<string>&current, vector<vector<string>>&result){
        //Base case 
        //if the index reaches the string's size
        
        if(index == s.length()){
            result.push_back(current);
            return;
        }
        
        //Check for the each substring 
        for(int i=index;i<s.length();i++){
            string substring = s.substr(index, i-index+1);
            
            //Check if the substring is a palindrome or not 
            if(isPalindrome(substring)){
                //Push it into current
                current.push_back(substring);
                //Call for the next index
                solve(s,i+1, current, result);
                //Pop the current result once it backtracks 
                current.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>current;
        solve(s,0,current,result);
        return result;
    }
};