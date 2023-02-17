class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>result;
        for(int i=nums.size()-1;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                result.push_back(-1);
            }
            else{
                result.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};