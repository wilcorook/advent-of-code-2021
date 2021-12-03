#include <iostream>
#include "day01/day01.h"
#include "day02/day02.h"
#include "day03/day03.h"

void LogResult(int result, char *day)
{
    std::cout << "result ";
    std::cout << day;
    std::cout << ": ";
    std::cout << result << std::endl;
}

int main(int argc, char const *argv[])
{
    LogResult(day01puzzle1(), "day01puzzle1");
    LogResult(day01puzzle2(), "day01puzzle2");
    LogResult(day02puzzle1(), "day02puzzle1");
    LogResult(day02puzzle2(), "day02puzzle2");
    LogResult(day03puzzle1(), "day03puzzle1");
}