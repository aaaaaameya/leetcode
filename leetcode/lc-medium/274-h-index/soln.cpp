#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());

        int h_index_max = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                h_index_max = std::max(h_index_max, i + 1);
            }
        }

        return h_index_max;
    }
};