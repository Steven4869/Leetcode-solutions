class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int temp=x;
        long sum =0;
        while(x!=0){
            int remainder = x%10;
            sum = sum*10 + remainder;
            x=x/10;
        }
        if(temp==sum)
            return true;
        else
            return false;
    }
};