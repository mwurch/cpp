#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        RPN  calculator;
        std::string term = argv[1];
        calculator.calculate(term);
    }
    else
    {
        if (argc < 2)
            std::cerr << "Not enough programm arguments. ./RPN [term]" << std::endl;
        else
            std::cerr << "Too many programm arguments. ./RPN [term]" << std::endl;
    }
    return 0;
}