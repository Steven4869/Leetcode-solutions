// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward.

// For example, 121 is a palindrome while 123 is not.
 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
#include<stdbool.h>
bool isPalindrome(int x){
    long sum = 0;
    int remainder;
    int temp=x;
    if(x<0)
        return false;
    while(x){
        remainder = x%10;
        sum = sum*10 + remainder;
        x=x/10;
    }
    if(temp==sum){
        return true;
    }
    else{
        return false;
    }