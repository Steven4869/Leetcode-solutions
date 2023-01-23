class Solution {
public:
    int numDecodings(string s) {
        //Recursion 
        //A character may be decoded alone or may be with pairing with other 
        //Make a recursive function to call when the string is not empty 
        
        //Changes to make it to Memo dp 
        int n = s.size();
        vector<int>mem(n+1, -1);
        mem[n]=1;
        return s.empty()?0:decodeWays(0, s, mem);
        
        // return s.empty()?0:decodeWays(0, s);
    }
//     int decodeWays(int pos, string &s){
//         int n = s.size();
//         //If position is the size then return 1;
//         if(pos==n)
//             return 1;
//         //Sub string starting with 0 is not a valid string 
//         if(s[pos]=='0')
//             return 0;
//         //Call it recursivley for the next string 
//         int result = decodeWays(pos+1, s);
//         //For the pair of two numbers 
//         //if it starts with 1 then any number can come but if with 2 then till 6 it can come
//         //as 26 is last number for the alphabet 
//         if(pos<n-1 &&(s[pos] == '1' || (s[pos]=='2'&&s[pos+1]<'7')))
//             result = result + decodeWays(pos+2, s);
//         return result;
        
//         //TC : O(2^N)
//         //To reduce TC we'll be using DP
//         //Memoisation 
//     }
    
    int decodeWays(int i, string &s, vector<int> &mem){
        //Base condition 
        if(mem[i]>-1) return mem[i];
        if(s[i]=='0') return mem[i] = 0;
        int res = decodeWays(i+1,s,mem);
        if(i<s.size()-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) res+=decodeWays(i+2,s,mem);
        return mem[i] = res;
        
    }
};