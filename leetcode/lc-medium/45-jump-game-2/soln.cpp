#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        std::queue<point> bfs;
        int end = nums.size() - 1;
        int max_reached = 0;

        bfs.push({0, 0});

        while (!bfs.empty()) {
            point front = bfs.front();
            bfs.pop();

            int index = front.index;
            int dist = front.dist;

            if (index == end) {
                return dist;
            }

            while (max_reached < std::min(index + nums[index], end)) {
                max_reached++;
                bfs.push({max_reached, dist + 1});
            }
        }

        return 0;
    }

private:
    struct point {
        int index;
        int dist;
    };
};