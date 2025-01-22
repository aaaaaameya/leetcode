#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int num_occurrences = 0;
        int curr_element = 0;
        int insert_counter = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                curr_element = nums[i];
                num_occurrences = 1;
            } else {
                num_occurrences++;
            }

            if (num_occurrences <= 2) {
                nums[insert_counter++] = nums[i];
            }
        }

        return insert_counter;
    }
};