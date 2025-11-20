#include <iostream>
#include "iter.hpp"

int main() {
    int *array = new int[5]{10, 20, 30, 40, 50};
    print(array, 5);
    iter(array, 5, change_value<int>);
    print(array, 5);
    delete[] array;
    return 0;
}
