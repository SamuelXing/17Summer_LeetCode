/*
* Say you have an array for which the ith element is the price of a given stock on day i.

* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int i = prices.size() - 1, ans = 0, maxp = prices[i];
        for(--i; i>=0; --i){
        	ans = max(ans, maxp - prices[i]);
        	maxp = max(maxp, prices[i]);
        }
        return ans;
    }
};
