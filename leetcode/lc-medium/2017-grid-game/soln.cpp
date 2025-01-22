#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        long long left_sum = 0;
        long long right_sum = 0;
        long long best_sum = LLONG_MAX;

        for (int i = grid[0].size() - 1; i >= 1; i--) {
            right_sum += (long long)grid[0][i];
        }

        for (int i = 0; i < grid[0].size(); i++) {
            best_sum = std::min(best_sum, std::max(left_sum, right_sum));

            left_sum += (long long)grid[1][i];
            if (i < grid[0].size() - 1) right_sum -= (long long)grid[0][i + 1]; 
        }

        return best_sum;
    }
};