class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int idx,int mask,vector<int>&nums1,vector<int>&nums2)
    {
        if(idx>=nums1.size())
        return 0;
        if(dp[idx][mask]!=-1)
        return dp[idx][mask];
        int ans=INT_MAX;
        for(int i=0 ;i<nums2.size();i++)
        {
          int bits= (1<<i);
          if(bits&mask)
          continue;
          ans= min (ans ,(nums1[idx]^nums2[i])+dfs(idx+1,mask|bits,nums1,nums2));
        }
        return dp[idx][mask]=ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) 
    {   
        dp.resize(nums1.size()+1 ,vector<int>(1<<nums2.size()+5,-1));
        return dfs(0,0,nums1,nums2);
    }
};