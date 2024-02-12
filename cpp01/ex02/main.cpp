#include <iostream>

int main( void )
{
    std::string str = "HI THIS IS BRAIN";

    std::string* strPTR = &str;
    std::string& strREF = str;

    std::cout << "Address of str:    " << &str << std::endl;
    std::cout << "Address of strref: " << &strREF << std::endl;
    std::cout << "Address of strptr: " << &strPTR << std::endl;

    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value of strref: " << strREF << std::endl;
    std::cout << "Value of strptr: " << *strPTR << std::endl;
}