class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int last = s.size()-1;
        while(start<=last){
            swap(s[start],s[last]);
            last--;
            start++;
        }
    }
};