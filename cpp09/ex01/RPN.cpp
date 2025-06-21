#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN & RPN::operator=(const RPN&) {return *this;}
RPN::RPN(const RPN&) {}

bool    RPN::isValid(const std::string& term)
{
    size_t opCount = 0, dCount = 0, index = 0;

    if (term.empty())
    {
        std::cerr << "Error: Empty expression" << std::endl;
        return false;
    }
    else if (term.find_first_of(DIGITS) == term.find_last_of(DIGITS) && term.find_first_of(OPERATOR) == std::string::npos)
    {
          std::cout << term[term.find_first_of(DIGITS)] - '0' << std::endl;
          return false;
    }
    else if (term.find_first_not_of(DIGITS + OPERATOR + " ") != std::string::npos)
    {
        std::cerr << "Error: Invalid character found" << std::endl;
        return false;
    }
    else if (term.find_first_of(DIGITS) > term.find_first_of(OPERATOR))
    {
        std::cerr << "Error: Invalid order of operators" << std::endl;
        return false;
    }

    while (term[index])
    {
        if (std::isdigit(term[index]))
            dCount++;
        else if (strchr(OPERATOR.c_str(), term[index]))
            opCount++;
        index++;
    }

    if (dCount-1 != opCount)
    {
        std::cerr << "Error: Invalid number of operands and operators" << std::endl;
        return false;
    }
    return true;
}

int     RPN::do_calculation(int operand1, int operand2, char op)
{
    switch(op)
    {
        case '+':
            return (operand1 + operand2);
        case '-':
            return (operand1 - operand2);
        case '*':
            return (operand1 * operand2);
        case '/':
            if (operand2 == 0) {
                throw (std::runtime_error("Division by zero"));
            }
            return (operand1 / operand2);
        default:
            throw("Invalid operator");
    }
}

void    RPN::calculate(const std::string& term)
{
    int operand1, operand2, result = 0;

    size_t index = 0;
    // clearing stack before starting a new calculation
    while(!_stack.empty())
        _stack.pop();
    // Errorhandling
    if (!isValid(term))
        return;
    // calculating result
    while (term[index])
    {
        while (std::isspace(term[index])) {index++;}
        if (std::isdigit(term[index]))
            _stack.push(term[index] - '0');
        else if (strchr(OPERATOR.c_str(), term[index]))
        {
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            operand2 = _stack.top();
            _stack.pop();
            operand1 = _stack.top();
            _stack.pop();
            try{
                result = do_calculation(operand1 , operand2, term[index]);
            } catch(std::exception &e) {
                std::cerr << "Error" << std::endl;
                return ;
            }
            _stack.push(result);
        }
        index++;
    }
    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << _stack.top() << std::endl;
}
