class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        int start = 0;
        int maxLen = 0;
        
        for(int i=0;i<n;i++){
            //For the odd palindrome 
            int left = i, right = i;
            while(left>=0 && right<n && s[left] == s[right]){
                left--;
                right++;
            }
            
            int len = right-left-1;
            if(len>maxLen){
                start = left+1;
                maxLen = len;
            }
            
            //For even Palindrome
            left = i, right = i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            len = right-left-1;
            if(len>maxLen){
                start = left+1;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
};