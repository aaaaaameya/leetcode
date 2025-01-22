#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy_price = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > buy_price) {
                profit += (prices[i] - buy_price);
                buy_price = prices[i];
            }
            buy_price = std::min(prices[i], buy_price);
        }

        return profit;
    }
};