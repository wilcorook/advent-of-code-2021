#include <iostream>
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

int day01puzzle2()
{
    int increased = 0;
    int previousSum = 0;

    std::vector<int> input;
    std::string fileName = "day01.txt";
    input = getNumbersFromFile(fileName.c_str(), 2000);

    for (int i = 0; i < input.size(); i++)
    {
        if ((input.size() - i) >= 3)
        {
            int sum = input[i] + input[i + 1] + input[i + 2];

            if (sum > previousSum && previousSum != 0)
            {
                increased++;
            }

            previousSum = sum;
        }
    }

    return increased;
}