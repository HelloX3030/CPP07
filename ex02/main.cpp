#include "Array.hpp"
#include <iostream>

int main(void) {
    // Basic int Array
    {
        Array<int> arr(20);
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] = i;
        }
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Test assignment operator" << std::endl;
        Array<int> arr2(20);
        arr2 = arr;
        arr2[10] = 100;
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        for (size_t i = 0; i < arr2.size(); i++) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Test copy constructor" << std::endl;
        Array<int> arr3(arr2);
        arr3[10] = 200;
        for (size_t i = 0; i < arr2.size(); i++) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;
        for (size_t i = 0; i < arr3.size(); i++) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;
    }

    // Basic float Array
    {
        Array<float> arr(20);
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] = static_cast<float>(i);
        }
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Basic std::string Array
    {
        Array<std::string> arr(20);
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] = "string" + std::to_string(i);
        }
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Test wrong Access" << std::endl;
        try {
            std::cout << arr[200] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
