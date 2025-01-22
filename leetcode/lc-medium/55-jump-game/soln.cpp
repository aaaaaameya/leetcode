#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int max_reached = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > max_reached) {
                return false;
            }

            max_reached = std::max(i + nums[i], max_reached);
        }

        return true;
    }
};