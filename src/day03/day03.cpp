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