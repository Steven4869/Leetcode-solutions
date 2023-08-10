class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            //Check if the mid value is greater than right value 
            if(nums[mid]>nums[right])
                left = mid+1;
            else if(nums[mid]<nums[right])
                right = mid;
            else 
                return nums[mid];
        }
        return -1;
    }
};