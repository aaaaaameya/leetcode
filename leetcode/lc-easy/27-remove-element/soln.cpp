#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int num_not_val = nums.size();
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == val) {
                int swap = nums[num_not_val - 1];
                nums[num_not_val - 1] = nums[i];
                nums[i] = swap;

                num_not_val--;
            }
        }

        return num_not_val;
    }
};