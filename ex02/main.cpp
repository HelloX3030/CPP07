#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

static void custom_tests()
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Custom Tests" << std::endl;

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

static int subject_tests()
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Subject Tests" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main(int, char**)
{
    custom_tests();
    return subject_tests();
}
