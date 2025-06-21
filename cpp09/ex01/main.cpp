#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        RPN  calculator;
        std::string term = argv[1];
        calculator.calculate(term);
    }
    else {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}