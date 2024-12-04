#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>

typedef long long int llint;

int possible[100][2];

// Check whether 2 integers have a difference of 1-3
bool diff_valid(llint i, llint j) {
    llint diff = std::abs(i - j);
    return (diff >= 1 && diff <= 3);
}

int main(int argc, char **argv) {

    // Open file at first argument
    std::string filename(argv[1]);
    std::vector<llint> entry;

    std::ifstream source;
    source.open(filename);
    std::string line;

    llint part1_total = 0;
    llint part2_total = 0;
    llint part2_total_v2 = 0;

    // Read each line in the file
    std::unordered_map<llint, llint> umap;
    int ct = 1;
    while (std::getline(source, line))
    {
        entry.clear();

        llint x, y;
        std::stringstream ss (line);

        // Insert the integers on the line into a vector
        while (ss >> x)
            entry.push_back (x);

        // PART 1:
        // Check if it is vacuously true/valid
        if (entry.size() == 0 || entry.size() == 1) {
            part1_total++;
            part2_total++;
            continue;
        }

        // Check if it is an increasing or decreasing sequence, with 1 <= difference <= 3
        int diff = std::abs(entry[1] - entry[0]);
        if (diff >= 1 && diff <= 3) {
            bool inc_not_dec = (entry[1] > entry[0]);
            bool valid = true;
            for (int i = 2; i < entry.size(); i++) {
                if ((entry[i] - entry[i-1]) > 0 && (!inc_not_dec || (entry[i] - entry[i-1]) > 3)) {
                    valid = false;
                    break;
                } else if ((entry[i] - entry[i-1]) < 0 && (inc_not_dec || (entry[i] - entry[i-1]) < -3)) {
                    valid = false;
                    break;
                } else if ((entry[i] - entry[i-1]) == 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) part1_total++;
        }

        // PART 2
        // Dynamic programming basecases at last and second-last in list
        possible[entry.size() - 1][0] = 1;
        possible[entry.size() - 1][1] = 1;
        
        possible[entry.size() - 2][0] = (entry[entry.size() - 1] != entry[entry.size() - 2]) && diff_valid(entry[entry.size() - 1], entry[entry.size() - 2]);
        possible[entry.size() - 2][1] = 1;

        if (entry.size() >= 3) {
            possible[entry.size() - 3][0] = (entry[entry.size() - 2] != entry[entry.size() - 3]) && ((entry[entry.size() - 3] < entry[entry.size() - 2]) == (entry[entry.size() - 2] < entry[entry.size() - 1])) && diff_valid(entry[entry.size() - 2], entry[entry.size() - 3]) && possible[entry.size() - 2][0];
            possible[entry.size() - 3][1] = (((entry[entry.size() - 2] != entry[entry.size() - 3]) && diff_valid(entry[entry.size() - 2], entry[entry.size() - 3]) && possible[entry.size() - 2][1]) ? 1 :
                                                ((entry[entry.size() - 1] != entry[entry.size() - 3]) && diff_valid(entry[entry.size() - 1], entry[entry.size() - 3]) ? 2 : 0));
        }

        if (entry.size() >= 4) {
            int i = entry.size() - 4;
            possible[i][0] = (entry[i] != entry[i+1]) && ((entry[i] < entry[i+1]) == (entry[i+1] < entry[i+2])) && diff_valid(entry[i], entry[i+1]) && possible[i+1][0];
            possible[i][1] = 0;
            if ((entry[entry.size() - 1] != entry[entry.size() - 3]) && diff_valid(entry[entry.size() - 1], entry[entry.size() - 3])) {
                possible[i][1] = (entry[i] != entry[i+1]) && ((entry[i] < entry[i+1]) == (entry[i+1] < entry[i+3])) && diff_valid(entry[i], entry[i+1]);
            }
            if (possible[i+1][1] == 1) {
                possible[i][1] = possible[i][1] || ((entry[i] != entry[i+1]) && ((entry[i] < entry[i+1]) == (entry[i+1] < entry[i+2])) && diff_valid(entry[i], entry[i+1]));
            }
            if (possible[i][1] == 0) {
                possible[i][1] = ((entry[i] != entry[i+2]) && ((entry[i] < entry[i+2]) == (entry[i+2] < entry[i+3])) && diff_valid(entry[i], entry[i+2]) && possible[i+2][0]) ? 2 : 0;
            }
        }

        // Dynamic programming induction
        for (int i = entry.size() - 5; i >= 0; i--) {
            possible[i][0] = (entry[i] != entry[i+1]) && ((entry[i] < entry[i+1]) == (entry[i+1] < entry[i+2])) && diff_valid(entry[i], entry[i+1]) && possible[i+1][0];
            if (possible[i+1][1] == 2) {
                possible[i][1] = (entry[i] != entry[i+1]) && ((entry[i] < entry[i+1]) == (entry[i+1] < entry[i+3])) && diff_valid(entry[i], entry[i+1]);
            } else if (possible[i+1][1] == 1) {
                possible[i][1] = (entry[i] != entry[i+1]) && ((entry[i] < entry[i+1]) == (entry[i+1] < entry[i+2])) && diff_valid(entry[i], entry[i+1]);
            } else {
                possible[i][1] = ((entry[i] != entry[i+2]) && ((entry[i] < entry[i+2]) == (entry[i+2] < entry[i+3])) && diff_valid(entry[i], entry[i+2]) && possible[i+2][0]) ? 2 : 0;
            }
        }

        if (possible[1][0] || possible[0][1]) part2_total++;

        // // PART 2 v2
        // // brute force solution
        // for (int rem = 0; rem < entry.size(); rem++) {
        //     std::vector<llint> next_entry(entry);
        //     next_entry.erase(next_entry.begin() + rem);

        //     if (next_entry.size() == 0 || next_entry.size() == 1) {
        //         part2_total_v2++;
        //         break;
        //     }

        //     int diff = std::abs(next_entry[1] - next_entry[0]);
        //     if (diff >= 1 && diff <= 3) {
        //         bool inc_not_dec = (next_entry[1] > next_entry[0]);
        //         bool valid = true;
        //         for (int i = 2; i < next_entry.size(); i++) {
        //             if ((next_entry[i] - next_entry[i-1]) > 0 && (!inc_not_dec || (next_entry[i] - next_entry[i-1]) > 3)) {
        //                 valid = false;
        //                 break;
        //             } else if ((next_entry[i] - next_entry[i-1]) < 0 && (inc_not_dec || (next_entry[i] - next_entry[i-1]) < -3)) {
        //                 valid = false;
        //                 break;
        //             } else if ((next_entry[i] - next_entry[i-1]) == 0) {
        //                 valid = false;
        //                 break;
        //             }
        //         }

        //         if (valid) {
        //             part2_total_v2++;
        //             break;
        //         }
        //     }
        // }

    }

    // Output to stdout
    std::cout << "Part 1: " << part1_total << std::endl;
    std::cout << "Part 2: " << part2_total << std::endl;
    return 0;
}
