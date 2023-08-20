class Solution {
public:
    
    int solve(int idx, vector<vector<int>>& offers, vector<int>&dp){
        if(idx == offers.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int notTake = solve(idx+1, offers, dp);
        int nextIdx = offers.size();
        
        int low = idx+1, high = offers.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(offers[mid][0] > offers[idx][1]){
                high = mid-1;
                nextIdx = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        int take = offers[idx][2] + solve(nextIdx, offers, dp);
        
        return dp[idx] = max(take, notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        int m = offers.size();
        vector<int>dp(m+1, -1);
        return solve(0, offers, dp);
    }
};