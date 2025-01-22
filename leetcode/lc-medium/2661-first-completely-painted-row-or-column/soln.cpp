#include <utility>
#include <vector>
#include <map>

class Solution {
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
        std::map<int, std::pair<int, int> > finder;

        int height = mat.size();
        int width = mat[0].size();

        int row_counter[100000] = {0};
        int col_counter[100000] = {0};

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                finder.insert({mat[y][x], std::make_pair(y, x)});
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            auto search = finder.find(arr[i]);
            int y = search->second.first;
            int x = search->second.second;

            row_counter[y]++;
            col_counter[x]++;
            if (row_counter[y] >= width || col_counter[x] >= height) {
                return i;
            }
        }

        return arr.size();
    }
};