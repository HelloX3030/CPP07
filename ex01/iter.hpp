#pragma once

#include <cstddef>

template <typename T>
void iter(T *array, const size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void iter(T *array, const size_t length, void (*func)(const T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void print(const T &array, const size_t length) {
    for (size_t i = 0; i < length; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void change_value(T &value) {
    value += 42;
}
