#include <vector>
#include <set>

/**
 * Oops, did this in O(n log n) instead of O(n) because I didn't realise it was a sorted array
 */

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::set<int> nums_set;
        int insert_counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums_set.contains(nums[i])) {
                nums[insert_counter++] = nums[i];
                nums_set.insert(nums[i]);
            }
        }

        return insert_counter;
    }
};