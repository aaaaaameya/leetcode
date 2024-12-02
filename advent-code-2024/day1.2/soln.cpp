#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <vector>
#include <unordered_map>

typedef long long int llint;

int main(int argc, char **argv) {
    
    // Open file at first argument
    std::string filename(argv[1]);
    std::vector<llint> left, right;

    std::ifstream source;
    source.open(filename);
    std::string line;

    // Read each line in the file
    std::unordered_map<llint, llint> umap;
    while (std::getline(source, line))
    {
        llint x, y;
        std::stringstream ss (line);

        // Insert the 2 integers on the line into 2 separate vectors
        while (ss >> x >> y)
            left.push_back (x);
            right.push_back (y);
        
        // Insert right variable into hash table, keeping count of occurrences
        auto result = umap.insert({ y, 1 });
        if (!result.second) {
            ++(result.first->second);
        }
    }
    
    // Find number of occurrences of each left variable in the right vector
    llint total = 0;
    for (int i = 0; i < left.size(); i++) {
        auto got = umap.find(left[i]);
        if (got != umap.end()) {
            total += left[i] * got->second;
        }
    }

    // Output to stdout
    std::cout << total << std::endl;
    return 0;
}
