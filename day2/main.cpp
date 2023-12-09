#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int part1(const std::vector<std::string> &lines) {
  const int RED = 12;
  const int GREEN = 13;
  const int BLUE = 14;
  const std::regex regBlue("[0-9]+ blue");
  const std::regex regGreen("[0-9]+ green");
  const std::regex regRed("[0-9]+ red");
  for (std::string line : lines) {
    std::smatch m;
    std::regex_search(line, m, regBlue);
    for (auto x : m)
      std::cout << x << " ";
    return 0;
  }
  return 1;
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

  part1(lines);
  return 0;
}
