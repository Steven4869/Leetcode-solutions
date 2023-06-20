class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(), -1);
        long long len = 2*k+1;
        long long sum =0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            if(i-len>=0){
                sum = sum - nums[i-len];
            }
            if(i>=len-1){
                ans[i-k]=sum/len;
            }
        }
        return ans;
    }
};