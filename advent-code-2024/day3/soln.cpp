#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <regex>

typedef long long int llint;

int main(int argc, char **argv) {

    // Open file at first argument
    std::string filename(argv[1]);
    std::vector<llint> entry;

    std::ifstream source(filename);
    std::stringstream buffer;
    buffer << source.rdbuf();

    std::string file = buffer.str();

    // PART 1
    // Pattern match for all mul(X,Y)
    {
        llint total = 0;
        std::regex mul_regex("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
        auto it_begin = std::sregex_iterator(file.begin(), file.end(), mul_regex);
        auto it_end = std::sregex_iterator();

        for (std::sregex_iterator i = it_begin; i != it_end; i++)
        {
            std::smatch match = *i;
            std::string match_str = match.str();

            std::regex digit_regex("[0-9]+");
            auto digit = std::sregex_iterator(match_str.begin(), match_str.end(), digit_regex);

            // First number
            std::smatch num1_match = *digit;
            std::string num1_str = num1_match.str();
            llint num1 = std::stoi(num1_str);

            // Second number
            digit++;
            std::smatch num2_match = *digit;
            std::string num2_str = num2_match.str();
            llint num2 = std::stoi(num2_str);
            
            total += num1 * num2;
        }

        std::cout << "Part 1: " << total << std::endl;
    }
    
    // PART 2
    // Pattern match for all mul(X,Y) or enable (do() or don't() commands)
    {
        llint total2 = 0;
        bool enabled = true;
        std::regex mul_regex("(mul\\([0-9]{1,3},[0-9]{1,3}\\)|do\\(\\)|don't\\(\\))");
        auto it_begin = std::sregex_iterator(file.begin(), file.end(), mul_regex);
        auto it_end = std::sregex_iterator();

        for (std::sregex_iterator i = it_begin; i != it_end; i++)
        {
            std::smatch match = *i;
            std::string match_str = match.str();

            // Enable commands
            if (match_str == "do()") {
                enabled = true;
                continue;
            } else if (match_str == "don't()") {
                enabled = false;
                continue;
            }

            if (!enabled) continue;

            std::regex digit_regex("[0-9]+");
            auto digit = std::sregex_iterator(match_str.begin(), match_str.end(), digit_regex);

            // First number
            std::smatch num1_match = *digit;
            std::string num1_str = num1_match.str();
            llint num1 = std::stoi(num1_str);

            // Second number
            digit++;
            std::smatch num2_match = *digit;
            std::string num2_str = num2_match.str();
            llint num2 = std::stoi(num2_str);
            
            total2 += num1 * num2;
        }

        std::cout << "Part 2: " << total2 << std::endl;
    }

    return 0;
}
