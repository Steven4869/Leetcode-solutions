class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zcnt=0; int ocnt=0; int tcnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
              zcnt++;
            if(nums[i]==1)
              ocnt++;
            if(nums[i]==2)
              tcnt++;
         }
        for(int i=0; i<nums.size(); i++){
            if(zcnt >0){
                nums[i]=0;
                zcnt--; 
            }
            else if(ocnt >0){
                nums[i]=1;
                ocnt--;
            }
            else if(tcnt >0){
                nums[i]=2;
                tcnt--; 
            }
        }
    }
};