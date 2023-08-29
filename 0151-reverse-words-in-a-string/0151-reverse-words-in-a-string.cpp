class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        
        int i = 0;
        int n = s.length();
        
        while(i<n){
            //getting to the point where the word starts 
            while(i<n && s[i]==' ')
                i++;
            
            if(i>=n)
                break;
            
            //Get the word 
            int j = i;
            while(j<n && s[j]!=' ')
                j++;
            
            string sub = s.substr(i, j-i);
            
            if(result.length() == 0)
                result = sub;
            else 
                result = sub + ' ' + result;
            i=j+1;
        }
        return result;
        
    }
};