#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int total_candy = 0;
        int back_pointer = 0;
        std::vector<int> candy(ratings.size(), 0);

        for (int i = 0; i < ratings.size(); i++) {
            if (i == 0 || ratings[i] == ratings[i - 1]) {
                candy[i] = 1;
                total_candy += 1;
                back_pointer = i + 1;
            } else if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
                total_candy += candy[i];
                back_pointer = i + 1;
            } else {
                candy[i] = 1;
                total_candy += 1;

                if (back_pointer == i) {
                    if (candy[i - 1] == 1) {
                        back_pointer--;
                    } else {
                        back_pointer = i + 1;
                        continue;
                    }
                }

                while (back_pointer > 0 &&
                    ratings[back_pointer] < ratings[back_pointer - 1] &&
                    candy[back_pointer] == candy[back_pointer - 1] - 1) {
                        back_pointer--;
                    }

                if (back_pointer < i) {
                    candy[back_pointer]++;
                    total_candy += (i - back_pointer);
                }
            }
        }

        return total_candy;
    }
};