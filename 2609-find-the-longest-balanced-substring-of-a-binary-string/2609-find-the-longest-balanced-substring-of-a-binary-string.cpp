class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = INT_MIN;
        int count_0 = 0;
        int count_1 = 0;
        for(int i=0;i<s.length();i++){
            int j = i;
            while(j<s.size()){
                if(s[j]=='0'){
                    count_0++;
                }
                else{
                    break;
                }
                j++;
            }
            while(j<s.size()){
                if(s[j]=='1'){
                    count_1++;
                }
                else{
                    break;
                }
                j++;
                if(count_0==count_1){
                    ans = max(ans, j-i);
                }
            }
            count_1=0;
            count_0=0;
        }
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
};