class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //We'll only get the profit line for the answer 
        //That is obtaining the increasing line 
        //We'll start from 1st index and go to the size of array
        //check the previous index if it's smaller than the later or not
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]<prices[i])
                profit=profit + (prices[i]-prices[i-1]);
        }
        return profit;
    }
};