#include <iostream>
#include"Harl.hpp"

int main(int argc, char **argv)
{
    int i;
    Harl obj;
    std::string input = argv[1];
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

    if (argc != 2)
        return (-1);
    for (i = 0; i < 4; i++)
    {
        if (input == levels[i])
            break ;
    }
    switch (i) {

    case 0:
        obj.complain("DEBUG");
        // Fall through intentionally
    case 1:
        obj.complain("INFO");
        // Fall through intentionally
    case 2:
        obj.complain("WARNING");
        // Fall through intentionally
    case 3:
        obj.complain("ERROR");
        break ;
    default:
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        break ;
} 

    return (0);
}