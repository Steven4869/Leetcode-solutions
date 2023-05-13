class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char>window;
        int left =0, right=0;
        int ans =0;
        while(right<n){
            char c = s[right];
            if(window.find(c)==window.end()){
                window.insert(c);
                ans = max(ans, right-left+1);
                right++;
            }
            else{
                window.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};