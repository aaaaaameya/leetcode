#include <vector>

/**
 * Implements Moore's voting algorithm to find the majority element
 */

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int element;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                element = nums[i];
                count++;
            } else {
                if (nums[i] == element) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return element;
    }
};