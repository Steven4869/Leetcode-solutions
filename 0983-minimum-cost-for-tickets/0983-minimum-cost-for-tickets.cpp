class Solution {
public:
    vector<int>dp;
    int minCost(vector<int>& days, vector<int>& costs, int start){
        int n = days.size();
        //Base Case
        if(start>=n)
            return 0;
        
        //For a single day cost
        int cost_day = costs[0] + minCost(days, costs, start + 1);
        
        int i;
        
        if(dp[start])
            return dp[start];
        //For week 
        //Skip to the week + starting day 
        for(i=start;i<n&&days[i]<days[start]+7;i++);
        int cost_week = costs[1] + minCost(days, costs, i);
        
        //For month 
        //Skip to the month + starting day 
        for(i=start;i<n&&days[i]<days[start]+30;i++);
        int cost_month = costs[2] + minCost(days, costs, i);
        
        
        dp[start] = min(cost_day, min(cost_week, cost_month));
        
        return dp[start];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //Cost for one day = cost[0] + cost of next day 
        //Cost for one week = cost[1] + cost of next day after week
        //Cost for one month = cost[2] + cost of next day after month 
        //Get the minimum of all three and that's the answer 
        
        dp.resize(366);
        return minCost(days, costs, 0);
    }
};