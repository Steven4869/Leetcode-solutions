class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int low = 0;
        int high = nums.size()-1;
        while(low<high){
            if(nums[low]+nums[high]==target){
                result.push_back(low+1);
                result.push_back(high+1);
                return result;
            }
            else if (nums[low]+nums[high]>target)
                high--;
            else 
                low++;

        }
        return result;
    }
};