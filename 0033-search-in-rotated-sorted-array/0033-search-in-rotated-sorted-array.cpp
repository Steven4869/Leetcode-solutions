class Solution {
public:
    int getPivot(vector<int> &nums){
        int n = nums.size();
        int s =0, e = n-1;
        while(s<e){
            int mid = s + (e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
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
        int n = nums.size();
        int pivot = getPivot(nums);
        int ans=-1;
        if((nums[pivot]<=target) && (target<=nums[n-1])){
           return solve_recur(nums, target, pivot, n-1);
        }
        else{
            return solve_recur(nums, target, 0, pivot-1);
        }
    }
};