#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <string>
#include <exception>
#include <cstring>
#include <stack>

const std::string  DIGITS = "1234567890";
const std::string  OPERATOR = "+-*/";

class RPN
{
    private:
        std::stack<int> _stack;
        RPN(const RPN&);
        RPN&           operator=(const RPN&);
        int             do_calculation(int operand1, int operand2, char op);
        bool            isValid(std::string term);
        
    public:

        RPN();
        ~RPN();
        void            calculate(std::string term);

};

#endif