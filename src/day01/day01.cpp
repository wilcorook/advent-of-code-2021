#include <string>
#include <vector>
#include "../util/util.h"

int day01puzzle1()
{
    int increased = 0;
    int previousMesurement = 0;

    std::vector<int> input;
    std::string fileName = "day01.txt";
    input = getNumbersFromFile(fileName.c_str(), 2000);

    for (int i : input)
    {
        if (i > previousMesurement && previousMesurement != 0)
        {
            increased++;
        }

        previousMesurement = i;
    }

    return increased;
}