#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int front_index = 0;
        int front_height = height[front_index];

        int back_index = height.size() - 1;
        int back_height = height[back_index];

        int total_volume = 0;

        while (front_index < back_index) {
            if (front_height <= back_height) {
                int next_height = height[front_index + 1];
                if (front_index + 1 < back_index && next_height < front_height) {
                    total_volume += (front_height - next_height);
                }

                front_index++;
                front_height = std::max(front_height, next_height);
            } else {
                int prev_height = height[back_index - 1];
                if (front_index < back_index - 1 && prev_height < back_height) {
                    total_volume += (back_height - prev_height);
                }

                back_index--;
                back_height = std::max(back_height, prev_height);
            }
        }

        return total_volume;
    }
};