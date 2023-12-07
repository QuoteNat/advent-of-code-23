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
    std::string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                           "eight", "nine"};
    std::map<std::string, int> numbers;
    for (int i = 0; i < sizeof(digits); i++)
    {
        numbers[digits[i]] = i;
        numbers[words[i]] = i;
    }
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
    return 0;
}