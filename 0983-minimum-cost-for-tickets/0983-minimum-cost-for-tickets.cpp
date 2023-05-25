class Solution {
public:
    
    int solve(vector<int>&days, vector<int>&costs, int idx, vector<int>&dp){
        //Base Case 
        //If index exceeds the size of days 
        if(idx>=days.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        //1 day pass 
        int sum =0;
        int option1 = costs[0] + solve(days, costs, idx+1, dp);
        
        //For 7 day pass 
        int i;
        for(i=idx;i<days.size()&&days[i]<days[idx]+7;i++);
        int option2 = costs[1] + solve(days, costs, i, dp);
        
        //For 30 days pass 
        for(i=idx;i<days.size()&&days[i]<days[idx]+30;i++);
        int option3 = costs[2] + solve(days, costs, i, dp);
        
        return dp[idx]=min(option1, min(option2, option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1, -1);
        return solve(days, costs, 0, dp);
    }
};