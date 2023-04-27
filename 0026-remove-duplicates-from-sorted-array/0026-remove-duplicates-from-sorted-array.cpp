class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique=0;
        for(int i=1;i<nums.size();i++){
            if(nums[unique]!=nums[i]){
                unique++;
                nums[unique]=nums[i];
            }
        }
        return unique+1;
        
    }
};