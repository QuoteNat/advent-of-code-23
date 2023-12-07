#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input;
    input.open("input");
    if (input.is_open())
    {
        std::string line;
        while (std::getline(input, line))
        {
            std::cout << line << std::endl;
        }
    }

    return 0;
}