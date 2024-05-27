#include "Array.hpp" // Include the header file with the Array template class


int main() {
    try {
        // Testing default constructor and size()
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl; // Output: 0

        // Testing parameterized constructor
        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl; // Output: 5

        // Testing operator[]
        for (size_t i = 0; i < arr2.size(); ++i) {
            arr2[i] = i * 10;
        }

        // Testing const version of operator[]
        const Array<int> constArr(5);
        std::cout << "Size of constArr: " << constArr.size() << std::endl; // Output: 5
        //constArr[0] = 10; // This line would cause a compilation error because constArr is const

        // Testing copy constructor
        Array<int> arr3(arr2);
        std::cout << "Size of arr3: " << arr3.size() << std::endl; // Output: 5
        for (size_t i = 0; i < arr3.size(); ++i) {
            std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl; // Output: arr3[0] = 0, arr3[1] = 10, ...
        }

        // Testing assignment operator
        Array<int> arr4;
        arr4 = arr3;
        std::cout << "Size of arr4: " << arr4.size() << std::endl; // Output: 5
        for (size_t i = 0; i < arr4.size(); ++i) {
            std::cout << "arr4[" << i << "] = " << arr4[i] << std::endl; // Output: arr4[0] = 0, arr4[1] = 10, ...
        }

        // Testing out-of-range access
        //std::cout << arr4[10] << std::endl; // This will throw an out_of_range exception

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
