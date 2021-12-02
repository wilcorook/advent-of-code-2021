#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> getNumbers()
{
    int size = 2000;
    std::vector<int> numbers;

    std::string fileName = "day01.txt";
    std::ifstream inputFile(fileName.c_str());
    int currInt;
    if (inputFile.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            inputFile >> currInt;
            numbers.push_back(currInt);
        }
    }
    else
    {
        std::cerr << "Can't open file\n";
    }

    return numbers;
}

int dewIt()
{
    int increased = 0;
    int previousMesurement = 0;

    std::vector<int> input;
    input = getNumbers();

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