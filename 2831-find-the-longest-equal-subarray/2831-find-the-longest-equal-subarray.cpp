class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        int ans =0, left =0, maxFreq =0;
        
        for(int right =0;right<nums.size();right++){
            mp[nums[right]]++;
            maxFreq = max(maxFreq, mp[nums[right]]);
            
            while((right-left+1)-maxFreq>k){
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans, maxFreq);
        }
        
        return ans;
    }
};