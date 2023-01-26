class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //We'll be going with two pointers solution 
        int left =0;//denoting the buy position 
        int right =1; //denoting the selling postion 
        int maxProfit = 0;
        //Run the loop until right pointer reaches to the end 
        while(right<prices.size()){
            //If right price is greater than left price then make up the profit 
            if(prices[left]<prices[right]){
                int profit = prices[right]-prices[left];
                maxProfit=max(maxProfit, profit);
            }
            //If that's not the case then make the left pointer to the right 
            else{
                left = right;
            }
            right++;
        }
        return maxProfit;
    }
};