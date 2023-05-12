class Solution {
public:
    string addBinary(string a, string b) {
        int carry =0;
        int i=a.size()-1;
        int j=b.size()-1;
        vector<int>result;
        while(i>=0||j>=0||carry!=0){
            int sum =0;
            if(i>=0){
                sum = sum + (a[i]-'0');
                i--;
            }
            if(j>=0){
                sum = sum + (b[j]-'0');
                j--;
            }
            sum = sum + carry;
            carry = sum/2;
            result.push_back(sum%2);
        }
        string ans;
        int idx=0;
        while(idx<result.size()){
            ans = ans + to_string(result[idx++]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};