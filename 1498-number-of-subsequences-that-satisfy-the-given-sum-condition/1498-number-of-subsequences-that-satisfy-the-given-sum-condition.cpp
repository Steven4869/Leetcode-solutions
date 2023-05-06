class Solution {
public:
    const int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int l = 0, r = nums.size() - 1;
        
        vector<int>powerof2(nums.size());
        powerof2[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            powerof2[i] = (powerof2[i-1] * 2)%mod;
        }
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ans += powerof2[r - l];
                ans %= mod;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};