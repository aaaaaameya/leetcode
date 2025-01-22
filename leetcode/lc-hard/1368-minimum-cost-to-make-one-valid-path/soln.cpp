#include <vector>
#include <tuple>
#include <queue>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        std::deque<std::tuple<int, int, int> > bfs;
        bool visited[100][100] = {0};
        int cost[100][100] = {0};

        int width = grid[0].size();
        int height = grid.size();

        bfs.push_back(std::make_tuple(height - 1, width - 1, 0));
        while (!bfs.empty()) {
            int y = std::get<0>(bfs.front());
            int x = std::get<1>(bfs.front());
            int least_cost = std::get<2>(bfs.front());
            bfs.pop_front();

            if (visited[y][x]) continue;
            visited[y][x] = true;
            cost[y][x] = least_cost;

            if (y == 0 && x == 0) {
                return least_cost;
            }

            if (x > 0 && !visited[y][x - 1]) {
                if (grid[y][x - 1] == 1) {
                    bfs.push_front(std::make_tuple(y, x - 1, least_cost));
                } else {
                    bfs.push_back(std::make_tuple(y, x - 1, least_cost + 1));
                }
            }

            if (x < width - 1 && !visited[y][x + 1]) {
                if (grid[y][x + 1] == 2) {
                    bfs.push_front(std::make_tuple(y, x + 1, least_cost));
                } else {
                    bfs.push_back(std::make_tuple(y, x + 1, least_cost + 1));
                }
            }

            if (y > 0 && !visited[y - 1][x]) {
                if (grid[y - 1][x] == 3) {
                    bfs.push_front(std::make_tuple(y - 1, x, least_cost));
                } else {
                    bfs.push_back(std::make_tuple(y - 1, x, least_cost + 1));
                }
            }

            if (y < height - 1 && !visited[y + 1][x]) {
                if (grid[y + 1][x] == 4) {
                    bfs.push_front(std::make_tuple(y + 1, x, least_cost));
                } else {
                    bfs.push_back(std::make_tuple(y + 1, x, least_cost + 1));
                }
            }
        }
        return 0;
    }
};
