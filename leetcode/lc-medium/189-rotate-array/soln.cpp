#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = (k % n);
        
        for (int i = 0; 2 * i < n; i++) {
            int swap = nums[n - i - 1];
            nums[n - i - 1] = nums[i];
            nums[i] = swap;
        }

        for (int i = 0; 2 * i < k; i++) {
            int swap = nums[k - i - 1];
            nums[k - i - 1] = nums[i];
            nums[i] = swap;
        }

        for (int j = 0; 2 * j < (n - k); j++) {
            int swap = nums[n - j - 1];
            nums[n - j - 1] = nums[k + j];
            nums[k + j] = swap;
        }
    }
};