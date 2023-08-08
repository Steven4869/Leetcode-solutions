class Solution {
public:
    int getPivot(vector<int>&nums){
        int left = 0;
        int right = nums.size()-1;
        
        while(left<right){
            int mid = left + (right - left)/2;
            if(nums[mid]>=nums[0])
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    int binarySearch(vector<int>&nums, int start, int end, int target){
        if(start>end)
            return -1;
        int mid = start + (end-start)/2;
        
        if(nums[mid] == target)
            return mid;
        
        else if(nums[mid]>target)
            return binarySearch(nums, start, mid-1, target);
        else
            return binarySearch(nums, mid+1, end, target);
        
    }
    int search(vector<int>& nums, int target) {
       int n = nums.size();
        int pivot = getPivot(nums);
        if((nums[pivot]<=target) && (target<=nums[n-1])){
           return binarySearch(nums, pivot, n-1, target);
        }
        else{
            return binarySearch(nums, 0, pivot-1, target);
        }
            
    }
};