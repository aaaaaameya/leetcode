#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <vector>

typedef long long int llint;
char wordsearch[200][200];

// Cardinal directions in the order E, SE, S, SW, W, NW, N, NE
int xdir[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int ydir[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(int argc, char **argv) {
    
    // Open file at first argument
    std::string filename(argv[1]);

    std::ifstream source;
    source.open(filename);

    std::string line;
    
    // Read the word search in the file
    int height = 0;
    int width = 0;
    int col = 0;
    while (std::getline(source, line))
    {
        col = 0;
        char x;
        std::stringstream ss (line);

        // Insert the 2 integers on the line into 2 separate vectors
        while (ss >> x) {
            wordsearch[height][col] = x;
            width = std::max(width, ++col);
        }
        
        height++;
    }

    // Find all XMAS matches
    {
        llint total = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (wordsearch[y][x] != 'X') continue;

                // Search in each direction
                for (int dir = 0; dir < 8; dir++) {
                    total += (0 <= x + 3*xdir[dir] && x + 3*xdir[dir] < width &&
                            0 <= y + 3*ydir[dir] && y + 3*ydir[dir] < height &&
                            // wordsearch[y][x] == 'X' &&
                            wordsearch[y+1*ydir[dir]][x+1*xdir[dir]] == 'M' &&
                            wordsearch[y+2*ydir[dir]][x+2*xdir[dir]] == 'A' &&
                            wordsearch[y+3*ydir[dir]][x+3*xdir[dir]] == 'S');
                }
            }
        }

        // Output answer to stdout
        std::cout << "Part 1: " << total << std::endl;
    }

    // Find all X-MAS matches, in a cross-fashion
    {
        llint total2 = 0;
        for (int y = 1; y < height - 1; y++) {
            for (int x = 1; x < width - 1; x++) {
                if (wordsearch[y][x] != 'A') continue;

                // Search in each direction
                total2 += (((wordsearch[y-1][x-1] == 'M' && wordsearch[y+1][x+1] == 'S') || (wordsearch[y-1][x-1] == 'S' && wordsearch[y+1][x+1] == 'M')) &&
                            ((wordsearch[y-1][x+1] == 'M' && wordsearch[y+1][x-1] == 'S') || (wordsearch[y-1][x+1] == 'S' && wordsearch[y+1][x-1] == 'M')));
            }
        }

        // Output answer to stdout
        std::cout << "Part 2: " << total2 << std::endl;
    }

    return 0;
}
