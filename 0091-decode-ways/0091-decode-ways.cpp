class Solution {
public:
    int numDecodingRecursive(string &s, int index){
        //If the index reaches to the string length 
        if(index == s.length())
            return 1;
        //If the string's index is 0 then return 0
        if(s[index] == '0')
            return 0;
        
        //For the single digit 
        int singleDigit = numDecodingRecursive(s, index+1);
        
        //For the double digit 
        int doubleDigit = 0;
        if(index+1<s.length() && (s[index] == '1' || (s[index] == '2' && 
                                                    s[index+1] <= '6'))){
            doubleDigit = numDecodingRecursive(s, index+2);
        }
        return singleDigit + doubleDigit;
    }
    int numDecodingMemo(string &s, int index, vector<int>&dp){
        if(index == s.length())
            return 1;
        if(s[index] == '0')
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        //For the single digit 
        int singleDigit = numDecodingMemo(s, index+1, dp);
        
        //For the double digit 
        int doubleDigit = 0;
        if(index+1<s.length() && (s[index] == '1' || (s[index] == '2' && 
                                                    s[index+1] <= '6'))){
            doubleDigit = numDecodingMemo(s, index+2, dp);
        }
        return dp[index] = singleDigit + doubleDigit;
        
    }
    int numDecodingTabulation(string &s, vector<int>&dp){
        int n = s.length();
        //If the dp is empty string
        dp[0]=1;
        
        //If the string index starts with 0 then put 0 otherwise 1 
        if(s[0] == '0')
            dp[1]=0;
        else
            dp[1]=1;
        
        //For single digit 
        for(int i=2;i<=n;i++){
            if(s[i-1] != '0')
                dp[i] = dp[i] + dp[i-1];
            
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
                dp[i] = dp[i] + dp[i-2];
        }
        return dp[n];
    }
    int numDecodings(string s) {
        // //Base conditions 
        // if(s.length() == 0 || s[0] == '0')
        //     return 0;
        // return numDecodingRecursive(s, 0);
        
        //Memo solution 
        // if(s.length() == 0 || s[0] == '0')
        //     return 0;
        // int n = s.length();
        // vector<int>dp(n, -1);
        // return numDecodingMemo(s, 0, dp);
        
        //Tabulation
        
        
        int n = s.length();
        vector<int>dp(n+1, 0);
        return numDecodingTabulation(s, dp);
        
    }
};