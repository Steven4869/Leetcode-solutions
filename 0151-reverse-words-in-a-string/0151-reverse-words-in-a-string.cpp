class Solution {
public:
    string reverseWords(string s) {
       string result="";
        int i=0;
        int n = s.length();
        while(i<n){
            //Get to the point where word starts
            while(i<n && s[i]==' '){
                i++;
            }
            if(i>=n){
                break;
            }
            //Get to the end of the word until first space is encountered
            int j = i;
            while(j<n&&s[j]!=' '){
                j++;
            }
            //Get the substring 
            string sub = s.substr(i, j-i);
            
            //If the result length is 0 then just add the sub string to it otherwise include space as well
            if(result.length()==0){
                result = sub;
            }
            else{
                result = sub + " " + result;
            }
            i=j+1;
            
        }
        return result;
    }
};