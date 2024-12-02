#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <vector>

typedef long long int llint;

int main(int argc, char **argv) {
    
    // Open file at first argument
    std::string filename(argv[1]);
    std::vector<llint> left, right;

    std::ifstream source;
    source.open(filename);
    std::string line;
    
    // Read each line in the file
    while (std::getline(source, line))
    {
        llint x, y;
        std::stringstream ss (line);

        // Insert the 2 integers on the line into 2 separate vectors
        while (ss >> x >> y)
            left.push_back (x);
            right.push_back (y);
    }
    
    // Sort the left and right vector
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // Find differences between each pair in the sorted vectors
    llint total = 0;
    for (int i = 0; i < left.size(); i++) {
        total += std::abs(left[i] - right[i]);
    }

    // Output to stdout
    std::cout << total << std::endl;
    return 0;
}
