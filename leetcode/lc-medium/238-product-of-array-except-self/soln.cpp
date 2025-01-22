#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> products(nums.size(), 1);

        int prefix_product = 1;
        for (int i = 0; i < nums.size(); i++) {
            products[i] *= prefix_product;
            prefix_product *= nums[i];
        }

        int suffix_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            products[i] *= suffix_product;
            suffix_product *= nums[i];
        }

        return products;
    }
};