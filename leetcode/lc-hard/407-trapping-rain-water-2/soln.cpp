#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int trapRainWater(std::vector<std::vector<int>>& heightMap) {
        std::priority_queue<Cell> pq;

        int height = heightMap.size();
        int width = heightMap[0].size();
        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

        for (int y = 0; y < height; y++) {
            pq.push(Cell(heightMap[y][0], y, 0));
            visited[y][0] = true;

            pq.push(Cell(heightMap[y][width - 1], y, width - 1));
            visited[y][width - 1] = true;
        }
        for (int x = 0; x < width; x++) {
            pq.push(Cell(heightMap[0][x], 0, x));
            visited[0][x] = true;

            pq.push(Cell(heightMap[height - 1][x], height - 1, x));
            visited[height - 1][x] = true;
        }

        int dy[4] = {0, 0, -1, 1};
        int dx[4] = {-1, 1, 0, 0};

        int volume = 0;
        while (!pq.empty()) {
            Cell curr = pq.top();
            pq.pop();

            int y = curr.y;
            int x = curr.x;
            int boundary = curr.height;

            for (int dir = 0; dir < 4; dir++) {
                int next_y = y + dy[dir];
                int next_x = x + dx[dir];

                if (isValidCell(next_y, next_x, height, width) &&
                    !visited[next_y][next_x]) {
                    int next_height = heightMap[next_y][next_x];

                    if (next_height < boundary) {
                        volume += boundary - next_height;
                    }

                    pq.push(Cell(std::max(next_height, boundary),
                                       next_y, next_x));
                    visited[next_y][next_x] = true;
                }
            }
        }

        return volume;
    }

    private:
        class Cell {
            public:
                int height;
                int y;
                int x;

                Cell(int minHeight, int row, int col) {
                    height = minHeight;
                    y = row;
                    x = col;
                }

                bool operator<(const Cell& other) const {
                    return height >= other.height;
                }
        };

    bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};
