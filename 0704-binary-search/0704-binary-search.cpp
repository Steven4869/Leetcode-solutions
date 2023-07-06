class Solution {
public:
    int solve(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        while(start<=end){
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid=start + (end-start)/2;
        }
        return -1;
    }
    int solve_recur(vector<int>& nums, int target, int start, int end){
        if(start>end){
            return -1;
        }
        int mid = start + (end-start)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return solve_recur(nums, target, start, mid-1);
        }
        else{
            return solve_recur(nums, target, mid+1, end);
        }
        
    }
    int search(vector<int>& nums, int target) {
        // return solve(nums, target);
        return solve_recur(nums, target, 0, nums.size()-1);
    }
};