#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        int num_rows = mat.size();
        int num_cols = mat[0].size();
        
        std::queue<Cell> bfs;
        std::vector<std::vector<bool>> visited(num_rows, std::vector<bool>(num_cols, false));
        std::vector<std::vector<int>> dist(num_rows, std::vector<int>(num_cols, 0));

        for (int row = 0; row < num_rows; row++) {
            for (int col = 0; col < num_cols; col++) {
                if (mat[row][col] == 0) {
                    bfs.push(Cell(0, row, col));
                    visited[row][col] = true;
                    dist[row][col] = 0;
                }
            }
        }

        int dRow[4] = {0, -1, 0, 1};
        int dCol[4] = {1, 0, -1, 0};
        while (!bfs.empty()) {
            Cell curr = bfs.front();
            bfs.pop();

            for (int dir = 0; dir < 4; dir++) {
                Cell next = Cell(curr.height + 1, curr.row + dRow[dir], curr.col + dCol[dir]);

                if (next.in_matrix(num_rows, num_cols) &&
                    !visited[next.row][next.col]) {
                    bfs.push(next);
                    visited[next.row][next.col] = true;
                    dist[next.row][next.col] = next.height;
                }
            }
        }

        return dist;
    }

private:
    class Cell {
    public:
        int height;
        int row;
        int col;
        
        Cell(int a, int b, int c) {
            height = a;
            row = b;
            col = c;
        }

        bool in_matrix(int num_rows, int num_cols) {
            return (row >= 0 && col >= 0 && row < num_rows && col < num_cols);
        }
    };
};