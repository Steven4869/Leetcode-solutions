class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen=0;
        int start=0;
        for(int i=0; i<s.length(); i++){
            int st=i; int end=i; 
            while(end >=0 && st< s.length() && s[st]==s[end]){
                  st++;
                  end--; 
            } 
            int cnt= st-end-1; 
            
            if(cnt > maxLen){
                maxLen=cnt;
                start=end+1; 
            }
            
            st=i; end=i+1;
            while(st>=0 && end< s.length() && s[st]==s[end]){
                st--;
                end++; 
            } 
            cnt= end-st-1; 
            if(cnt > maxLen){
                maxLen=cnt;
                start=st+1; 
            }
        }
        return s.substr(start,maxLen); 
    }
};