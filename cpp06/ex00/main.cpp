#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        return -1;
    std::string input = argv[1];
    try{
        ScalarConverter::convert(input);
    }catch(std::exception &e)
    {
        std::cerr << "Impossible to convert: " << e.what() << std::endl;
    }
    return 0;
}