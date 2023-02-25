//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/editorial/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyPrice=prices[0];
        int len = prices.size();
        for(int i=1;i<len;i++){
            if(prices[i] > buyPrice){
                maxProfit = max(maxProfit, prices[i]-buyPrice);
            }

            if(prices[i] < buyPrice){
                buyPrice = prices[i];
            }
        }
        return maxProfit;
    }
};