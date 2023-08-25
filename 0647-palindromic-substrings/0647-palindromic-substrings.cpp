class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i, j, s)){
                    count++;
                }
            }
        }
        return count;
    }
};