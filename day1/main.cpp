#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main()
{
    std::string line;
    const std::string NUMBERS = "1234567890";
    std::ifstream input;
    input.open("input");
    std::vector<std::string> calibrationNumbers = std::vector<std::string>();

    if (input.is_open())
    {
        while (std::getline(input, line))
        {
            std::stringstream number = std::stringstream();
            int digit1Index = line.find_first_of(NUMBERS);
            int digit2Index = line.find_last_of(NUMBERS);
            number << line.at(digit1Index) << line.at(digit2Index);
            calibrationNumbers.push_back(number.str());
        }
    }

    int sum = 0;
    for (std::string numString : calibrationNumbers)
    {
        sum += std::stoi(numString);
    }

    std::cout << "(Part 1) Sum of all calibration values is: " << sum << std::endl;
    return 0;
}