class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i=i+2*k){
            if(i+k<=s.length()){
                reverse(s.begin()+i, s.begin()+i+k);
            }
            else{
                reverse(s.begin()+i, s.end());
            }
        }
        
        return s;
    }
};