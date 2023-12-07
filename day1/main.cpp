#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

/// @brief Solution to part 1
/// @param lines Lines of the input file
/// @return Sum of all calibration values
int part1(const std::vector<std::string> &lines)
{
    const std::string NUMBERS = "1234567890";
    std::vector<std::string> calibrationNumbers;

    for (std::string line : lines)
    {
        std::stringstream number = std::stringstream();
        int digit1Index = line.find_first_of(NUMBERS);
        int digit2Index = line.find_last_of(NUMBERS);
        number << line.at(digit1Index) << line.at(digit2Index);
        calibrationNumbers.push_back(number.str());
    }

    int sum = 0;
    for (std::string numString : calibrationNumbers)
    {
        sum += std::stoi(numString);
    }
    return sum;
}

int part2(const std::vector<std::string> &lines)
{
    /**
     * Create a map of substrings to look for and the
     */
    std::vector<std::string> digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector<std::string> words = {"one", "two", "three", "four", "five", "six", "seven",
                                      "eight", "nine"};
    std::map<std::string, int> numbers;
    for (int i = 0; i < 9; i++)
    {
        numbers[digits[i]] = i + 1;
        numbers[words[i]] = i + 1;
    }
    // Calculate sum from lines
    int sum = 0;
    for (std::string line : lines)
    {
        int digit1 = 0;
        int firstIndex = line.length();
        int digit2 = 0;
        int lastIndex = -1;
        for (auto it = numbers.begin(); it != numbers.end(); it++)
        {
            // Find the number substring closest to the start
            int index = line.find(it->first);
            if (index != std::string::npos && index < firstIndex)
            {
                firstIndex = index;
                digit1 = it->second;
            }

            // Find the number substring closest to the end
            index = line.rfind(it->first);
            if (index != std::string::npos && index > lastIndex)
            {
                lastIndex = index;
                digit2 = it->second;
            }
        }

        // Fun with base 10
        sum += 10 * digit1 + digit2;
    }

    return sum;
}

int main()
{
    std::string line;
    std::ifstream input;
    input.open("input");

    std::vector<std::string> lines;
    if (input.is_open())
    {
        while (std::getline(input, line))
        {
            lines.push_back(line);
        }
    }
    input.close();

    std::cout << "(Part 1) Sum of all calibration values is: " << part1(lines) << std::endl;
    std::cout << "(Part 2) Sum of all calibration values is: " << part2(lines) << std::endl;
    return 0;
}