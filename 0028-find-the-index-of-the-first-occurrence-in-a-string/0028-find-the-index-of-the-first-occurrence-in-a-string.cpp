class Solution {
public:
    vector<int> buildLpsArray(string &s){
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
                if(len!=0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    int strStr(string haystack, string needle) {
        //using KMP 
        
        //Build the LPS array
        int n = haystack.size();
        int m = needle.size();
        vector<int>lps = buildLpsArray(needle);
        
        int i=0, j=0;
        
        while(i<n){
            if(needle[j] == haystack[i]){
                i++;
                j++;
            }
            
            if(j==m){
                return i-j;
            }
            else if(i<n && needle[j] != haystack[i]){
                if(j!=0)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
};