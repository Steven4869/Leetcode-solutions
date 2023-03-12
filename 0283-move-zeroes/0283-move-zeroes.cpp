class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Count the number of zeros 
        int zeros = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }
        }
        
        //Make another vector and store non zero elements 
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                result.push_back(nums[i]);
            }
        }
        
        //Push the zeros now 
        while(zeros--){
            result.push_back(0);
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i]=result[i];
        }
        
    }
};