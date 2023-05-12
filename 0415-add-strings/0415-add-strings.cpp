class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        vector<int>result;
        while(i>=0||j>=0||carry!=0){
            int sum =0;
            if(i>=0){
                sum = sum + (num1[i]-'0');
                i--;
            }
            if(j>=0){
                sum = sum + (num2[j]-'0');
                j--;
            }
            
            sum = sum + carry;
            carry = sum/10;
            result.push_back(sum%10);
        }
        
        string ans="";
        int idx=0;
        while(idx<result.size()){
            ans = ans + to_string(result[idx++]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};