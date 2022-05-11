// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

 

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

class Solution {
public:
    bool isHappy(int n) {
        int temp=0;
        int sum =0;
        int count =0;
        if(n==1)
            return true;
        
        while(count<1000){
            temp = n%10; // To get the digit 
            sum = sum + temp*temp; //square of that last digit 
            n=n/10;// to get the first digit 
            //itrtating the loop and adding into count until n =0
            //if n =0 and sum =1 then return true else make n = sum and sum =0 temp =0;
            //Otheriwse false
            if(n==0){
                if(sum ==1)
                    return true;
                n=sum;
                temp=0;
                sum=0;
            }
            count++;
        }
        return false;
    }
};