class Solution {
public:
    int solveLIS(vector<vector<int>>&cuboid, int curr, int prev, vector<vector<int>>&dp){
        if(curr==cuboid.size())
            return 0;
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        
        int take = 0;
        if(prev==-1||((cuboid[curr][2]>=cuboid[prev][2])&&(cuboid[curr][1]>=cuboid[prev][1]))){
            take = cuboid[curr][2] + solveLIS(cuboid, curr+1, curr, dp);
        }
        
        int notTake = 0 + solveLIS(cuboid, curr+1, prev, dp);
        return dp[curr][prev+1] = max(take, notTake);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //sort every element of cuboid
        for(auto &c:cuboids){
            sort(c.begin(), c.end());
        }
        //Sort based on width
        sort(cuboids.begin(), cuboids.end());
        
        //Performing LIS for the last index 
        vector<vector<int>>dp(cuboids.size()+1, vector<int>(cuboids.size()+1, -1));
        return solveLIS(cuboids, 0, -1, dp);
    }
};