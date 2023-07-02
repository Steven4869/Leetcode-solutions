class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int count = 0;
            if(nums[i]%2==0){
                int j;
                for(j=i+1;j<nums.size();j++){
                    if((nums[j-1]%2!=nums[j]%2)&&(nums[j-1])<=threshold){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if(nums[j-1]<=threshold){
                    count++;
                }
                
            }
            ans = max(count, ans);
        }
        return ans;
    }
};