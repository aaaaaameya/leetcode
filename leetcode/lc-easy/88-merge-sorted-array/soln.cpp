#include <vector>
#include <queue>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::queue<int> q;
        
        int i = 0;
        int j = 0;
        while (i < m || j < n) {
            if (i >= m) {
                q.push(nums2[j]);
                j++;
            } else if (j >= n) {
                q.push(nums1[i]);
                i++;
            } else {
                if (nums1[i] <= nums2[j]) {
                    q.push(nums1[i]);
                    i++;
                } else {
                    q.push(nums2[j]);
                    j++;
                }
            }
        }

        for (int k = 0; k < m + n; k++) {
            int curr = q.front();
            q.pop();
            nums1[k] = curr;
        }
    }
};
