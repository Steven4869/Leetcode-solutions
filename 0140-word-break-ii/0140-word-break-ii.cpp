class Solution {
public:
   void solve(string &s, int index, string current, vector<string>&result, unordered_set<string>&dict){
       //Base Case 
       if(index == s.length()){
           current.pop_back();
           result.push_back(current);
       }
       
       string str="";
       
       for(int i=index;i<s.length();i++){
           str.push_back(s[i]);
           if(dict.count(str)){
               solve(s,i+1, current+str+" ", result, dict);
           }
       }
   }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        vector<string>result;
        string current = "";
        solve(s, 0, current, result, dict);
        return result;
    }
};