class Solution {
public:
    int getSum(int a, int b) {
        int sum = a^b;
        int carry = a&b;
        
        if(carry == 0)
            return sum;
        else
            return getSum(sum, carry<<1);
    }
};