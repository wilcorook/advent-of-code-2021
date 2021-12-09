#include <iostream>
#include <string>
#include <vector>
#include "../util/util.h"

int day03puzzle1()
{
    std::string gammaStr = "";
    std::string epsilonStr = "";
    std::vector<std::string> input;
    std::string fileName = "day03.txt";
    input = getStringsFromFile(fileName.c_str(), 1000);

    // character
    for (int i = 0; i < 12; i++)
    {
        int zero = 0;
        int one = 0;

        // line
        for (int c = 0; c < 1000; c++)
        {
            if (input[c][i] == '0')
            {
                zero++;
            }
            if (input[c][i] == '1')
            {
                one++;
            }
        }

        if (zero > one)
        {
            gammaStr += std::to_string(0);
            epsilonStr += std::to_string(1);
        }
        else
        {
            gammaStr += std::to_string(1);
            epsilonStr += std::to_string(0);
        }

        zero = 0;
        one = 0;
    }

    int gammaDecimal = std::stoi(gammaStr, 0, 2);
    int epsilonDecimal = std::stoi(epsilonStr, 0, 2);

    return gammaDecimal * epsilonDecimal;
}

int findOxygenNumbers(std::vector<std::string> input, int pos)
{
    int zero = 0;
    int one = 0;

    // line
    for (int c = 0; c < input.size(); c++)
    {
        if ((char)input[c][pos] == '0')
        {
            zero++;
        }
        if ((char)input[c][pos] == '1')
        {
            one++;
        }
    }

    if (zero == one)
    {
        return 1;
    }
    else if (zero > one)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int findCO2Numbers(std::vector<std::string> input, int pos)
{
    int zero = 0;
    int one = 0;

    // line
    for (int c = 0; c < input.size(); c++)
    {
        if ((char)input[c][pos] == '0')
        {
            zero++;
        }
        if ((char)input[c][pos] == '1')
        {
            one++;
        }
    }

    if (zero == one)
    {
        return 0;
    }
    else if (zero > one)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void removeNumbers(std::vector<std::string> &input, int index, int bit)
{
    char compareChar;
    if (bit == 0)
    {
        compareChar = 48;
    }
    else
    {
        compareChar = 49;
    }

    for (int i = 0; i < input.size(); i++)
    {

        if ((char)input[i][index] != compareChar)
        {
            input.erase(input.begin() + i);
            // decrease i because the vector size was just decreased
            i--;
        }
    }
}

int day03puzzle2()
{
    std::vector<std::string> input;
    std::string fileName = "day03.txt";
    input = getStringsFromFile(fileName.c_str(), 1000);
    std::vector<std::string> oxygen(input);
    std::vector<std::string> co2(input);

    // check for most and least common, remove from vectors accordingly
    for (int i = 0; i < 12; i++)
    {
        int oxy = findOxygenNumbers(oxygen, i);
        int co = findCO2Numbers(co2, i);

        removeNumbers(oxygen, i, oxy);
        removeNumbers(co2, i, co);

        if (oxygen.size() == 1 && co2.size() == 1)
        {
            break;
        }
    }

    int oxygenDecimal = std::stoi(oxygen[0], 0, 2);
    int co2Decimal = std::stoi(co2[0], 0, 2);

    return oxygenDecimal * co2Decimal;
}