class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goalPost = n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=goalPost){
                goalPost = i;
            }
        }
        
        if(goalPost == 0)
            return true;
        return false;
    }
};