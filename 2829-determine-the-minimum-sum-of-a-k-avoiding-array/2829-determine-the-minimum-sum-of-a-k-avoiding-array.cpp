class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int>st;
        
        int sum = 0;
        for(int i=1;st.size()<n;i++){
            //If it is not in the set
            if(st.find(k-i) == st.end()){
                st.insert(i);
                sum = sum + i;
            }
        }
        return sum;
    }
};