//Leetcode TwoSum Problem 
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
int *TwoSum(int *nums, int numsSize, int target, int * returnSize){
    //nums refer to the array, numsSize refers to the size of the array, target refers indices of number that add up to the said target and returnSize refers to the length of returning array

    int i, j;
    //Allocating a result array for the printing of the indices that will add up to the target
    int *result = (int*)malloc(2*sizeof(int));
    *returnSize=2;
    //We'll traverse the array first with i and then take j to get the next indice. Compare elemts of the ith and jth to check if they match with the target or not.
   for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i] + nums[j] == target){
                result[0]=i;
                result[1]=j;
            }
        }
    }
    return result;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end())
                return {map[target-nums[i]], i};
            else 
                map[nums[i]]=i;
        }
        return {};
    }
};