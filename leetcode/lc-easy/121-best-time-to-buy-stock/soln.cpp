#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_tracked = 10001;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            min_tracked = std::min(prices[i], min_tracked);
            max_profit = std::max(prices[i] - min_tracked, max_profit);
        }

        return max_profit;
    }
};