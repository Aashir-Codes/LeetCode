class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int brought_stocks=prices[0];
        int sold_stocks=0;
        for (int i=1;i<prices.size();i++)
        {
            if(prices[i]<=brought_stocks)
            {
                brought_stocks=prices[i];
            }
            else if(sold_stocks<prices[i]-brought_stocks)
            {
                sold_stocks=prices[i]-brought_stocks;
            }

        }


        return sold_stocks;
    }
};