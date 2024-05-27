#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <limits>

int main() {
    try {
        // Test Span construction and addition of numbers
        Span span(10);
        span.addNumber(std::numeric_limits<int>::max());
        span.addNumber(std::numeric_limits<int>::min());
        span.addNumber(std::numeric_limits<int>::min() + 3);

        // Test filling Span from a vector
        std::vector<int> vec;
        vec.push_back(20);
        vec.push_back(25);
        vec.push_back(30);
        span.fillSpan(vec.begin(), vec.end());

        // Test filling Span from a list
        std::list<int> lst;
        lst.push_back(35);
        lst.push_back(40);
        lst.push_back(45);
        span.fillSpan(lst.begin(), lst.end());

        // Test calculating shortest and longest spans
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
