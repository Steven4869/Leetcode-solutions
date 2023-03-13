class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result(nums.size());
        int low = 0;
        int high = nums.size()-1;
        int counter = nums.size()-1;
        
        while(low<=high){
            if(abs(nums[low])>abs(nums[high])){
                result[counter--]=nums[low]*nums[low];
                low++;
            }
            else{
                result[counter--]=nums[high]*nums[high];
                high--;
            }
        }
        return result;
        
    }
};