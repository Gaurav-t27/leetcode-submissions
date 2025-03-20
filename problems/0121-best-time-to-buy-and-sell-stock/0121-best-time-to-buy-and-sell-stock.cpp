class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;

        int l=0,r=1;
        int maxProfit = 0;
        while(l<prices.size() && r<prices.size())
        {
            int profit = 0;
            if(prices[r]-prices[l] > 0)
            {
                profit = prices[r] - prices[l];
                maxProfit = max(profit,maxProfit);
                r++;
            }
            else
            {
                l = r;
                r++;
            }
        }
        return maxProfit;
    }
};