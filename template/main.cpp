#include <iostream>
#include <fstream>

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

    return 0;
}
