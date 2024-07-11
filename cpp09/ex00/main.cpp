#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void) argv;
    if (argc == 2)
    {
        try{
            BitcoinExchange btc("data.csv");
            btc.analzyeInputfile(argv[1]);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else{
        if (argc < 2)
            std::cerr << "Not enough programm arguments. ./btc [inputfile]" << std::endl;
        else
            std::cerr << "Too many programm arguments. ./btc [inputfile]" << std::endl;
    }
}