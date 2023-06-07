class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minAmount = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            int diff = prices[i]-minAmount;
            profit = max(profit, diff);
            //Updating minAmount for the future check
            minAmount = min(minAmount, prices[i]);
        }
        return profit;
    }
};