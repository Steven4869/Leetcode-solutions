class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNegative=0;
        int countZero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                countNegative++;
            }
            else if(nums[i]==0){
                countZero++;
            }
        }
        if(countNegative%2==0 && countZero==0){
            return 1;
        }
        else if(countNegative%2!=0 && countZero==0){
            return -1;
        }
        else if(countZero!=0){
            return 0;
        }
        return 0;
    }
};