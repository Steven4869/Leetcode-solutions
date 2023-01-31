class Solution {
public:
    int recur(int nums, int curr){
        if(nums==0||curr==0)
            return 1;
        
        if(curr>nums)
            return recur(nums, curr-1);
        else 
            return max(recur(nums, curr-1), curr*recur(nums-curr, curr));
        
    }
    int integerBreak(int n) {
        //This problem is variation of rod cutting problem
        //Basic approach would be to go with recursion 
        //Make up a recursion function and get the value of the n from 1 to n-1
        //We cannot take 0 as the value 
        
        return recur(n, n-1);
    }
};