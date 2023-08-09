class Solution {
public:
    
    bool isValid(vector<int>&nums, int mid, int p){
        int count =0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=mid){
                count++;
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int start =0, end = 1e9;
        int mid, result;
        while(start<=end){
            mid = start + (end-start)/2;
            //Checking if mid can be the answer 
            if(isValid(nums, mid, p)){
                result = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return result;
    }
};