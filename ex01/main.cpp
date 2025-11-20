#include <iostream>
#include <vector>

#include "iter.hpp"

int main() {
    // Base int Array
    int *array = new int[5]{10, 20, 30, 40, 50};
    iter(array, 5, print_value<int>);
    std::cout << std::endl;
    iter(array, 5, change_value<int>);
    iter(array, 5, print_value<int>);
    std::cout << std::endl;
    delete[] array;

    // Base double Array
    double *d_array = new double[5]{1.1, 2.2, 3.3, 4.4, 5.5};
    iter(d_array, 5, print_value<double>);
    std::cout << std::endl;
    iter(d_array, 5, change_value<double>);
    iter(d_array, 5, print_value<double>);
    std::cout << std::endl;
    delete[] d_array;

    // Base String Array
    std::string *s_array = new std::string[5]{"one", "two", "three", "four", "five"};
    iter(s_array, 5, print_value<std::string>);
    std::cout << std::endl;
    iter(s_array, 5, set_string);
    iter(s_array, 5, print_value<std::string>);
    std::cout << std::endl;
    delete[] s_array;
    return 0;
}
