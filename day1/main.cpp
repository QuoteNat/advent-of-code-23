#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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