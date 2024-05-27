#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {
    
    int initial_values[] = {10, 20, 30, 40, 50};
    std::vector<int> vec(initial_values, initial_values + sizeof(initial_values) / sizeof(int));

    int target = 60;

    try {
        std::vector<int>::iterator it = easyfind(vec, target);
        std::cout << "Element " << target << " found at index: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const IntNotFoundException& e) {
        std::cout << "Element not found: " << e.what() << std::endl;
    }

    return 0;
}

