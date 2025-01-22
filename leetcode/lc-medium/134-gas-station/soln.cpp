#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int start_index = 0;
        int current_end_index = 0;
        int current_gas = 0;

        while (start_index < gas.size()) {
            bool inc_end_index = true;
            current_gas += (gas[current_end_index] - cost[current_end_index]);
            
            while (current_gas < 0) {
                if (start_index != current_end_index) {
                    current_gas -= (gas[start_index] - cost[start_index]);
                    if (start_index != gas.size() - 1) {
                        start_index++;
                    } else {
                        return -1;
                    }
                } else {
                    current_gas = 0;
                    if (start_index != gas.size() - 1) {
                        start_index++;
                    } else {
                        return -1;
                    }
                    current_end_index = start_index;
                    inc_end_index = false;
                }
            }

            if (inc_end_index) {
                if (current_end_index != gas.size() - 1) {
                    current_end_index++;
                } else {
                    current_end_index = 0;
                }
                
                if (start_index == current_end_index) {
                    return start_index;
                }
            }
        }

        return -1;
    }
};
