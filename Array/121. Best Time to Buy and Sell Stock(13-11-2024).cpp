/*
Logic

1. Brute Force Approach:
a. On the first day, the only possible action is to buy the stock.
b. Start iterating from day 1 (index 1).
c. For each day, calculate the potential profit by comparing the current day's price with the minimum price seen so far.
d. Update the maximum profit if the current day's profit is higher.
e. Track the minimum price at which to buy the stock as you iterate.

Time Complexity: O(N)
Space Complexity: O(1)

2. Optimal Approach:
- The logic remains the same, with efficient tracking of the minimum price and maximum profit.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minBuy= prices[0];
        int maxSell = -1;
        for(int i=1;i<prices.size();++i){
            maxPro = max(maxPro, prices[i]-minBuy);
            minBuy = min(minBuy,prices[i]);
        }
        return maxPro;
    }
};
