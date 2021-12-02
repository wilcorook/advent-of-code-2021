#include <iostream>
#include <string>
#include <vector>
#include "../util/util.h"

int day02puzzle1()
{
    int horizontal = 0;
    int depth = 0;

    std::vector<std::string> input;
    std::string fileName = "day02puzzle1.txt";
    // size 2 * amout of lines
    input = getStringsFromFile(fileName.c_str(), 2000);

    for (int i = 0; i < input.size(); i += 2)
    {
        std::string direction = input[i];
        int amount = std::stoi(input[i + 1]);

        if (direction == "forward")
        {
            horizontal += amount;
        }
        else if (direction == "down")
        {
            depth += amount;
        }
        else if (direction == "up")
        {
            depth -= amount;
        }
    }

    std::cout << horizontal << std::endl;
    std::cout << depth << std::endl;

    return horizontal * depth;
}