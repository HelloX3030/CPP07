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
    }
}
