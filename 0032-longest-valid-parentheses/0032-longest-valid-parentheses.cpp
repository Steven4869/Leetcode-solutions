class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        
        int maxLen = 0;
        for(int i=0;i<s.length();i++){
            int top = st.top();
            if(top!=-1 && (s[i] == ')' && s[top] == '(')){
                st.pop();
                maxLen = max(maxLen, i-st.top());
            }
            else{
                st.push(i);
            }
        }
        
        return maxLen;
    }
};