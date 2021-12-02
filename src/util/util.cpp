#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> getNumbersFromFile(const char *fileName, int fileSize)
{
    std::vector<int> numbers;

    std::ifstream inputFile(fileName);
    int currInt;
    if (inputFile.is_open())
    {
        for (int i = 0; i < fileSize; i++)
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

std::vector<std::string> getStringsFromFile(const char *fileName, int fileSize)
{
    std::vector<std::string> strings;

    std::ifstream inputFile(fileName);
    std::string currStr;
    if (inputFile.is_open())
    {
        for (int i = 0; i < fileSize; i++)
        {
            inputFile >> currStr;
            strings.push_back(currStr);
        }
    }
    else
    {
        std::cerr << "Can't open file\n";
    }

    return strings;
}