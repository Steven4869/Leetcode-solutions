class Solution {
public:
    bool repeatedSubstringPattern(string s) {
//         int n = s.length();
        
//         for(int len=1;len<=n/2;len++){
//             if(n%len == 0){
//                 string substring = s.substr(0, len);
//                 string formed = "";
                
//                 for(int i=0;i<n/len;i++){
//                     formed = formed + substring;
//                 }
//                 if(formed == s)
//                     return true;
//             }
//         }
//         return false;
        
        //Using KMP 
        
        int n = s.length();
        vector<int>lps(n,0);
        int len = 0;
        int i = 1;
        
        while(i<n){
            if(s[i] == s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        int patternLength = lps[n-1];
        int repeatedLength = n - patternLength;
        
        if(patternLength > 0 && n%repeatedLength == 0)
            return true;
        
        return false;
    }
};