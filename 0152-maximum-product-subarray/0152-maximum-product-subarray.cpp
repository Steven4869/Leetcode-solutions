class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int currMax = 1;
        int currMin = 1;
        
        for(int i=0;i<nums.size();i++){
            int tmp = currMax*nums[i];
            currMax = max(nums[i]*currMax, max(nums[i]*currMin, nums[i]));
            currMin = min(tmp, min(nums[i]*currMin, nums[i]));
            result = max(result, currMax);
        }
        return result;
    }
};