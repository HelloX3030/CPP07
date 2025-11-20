#pragma once

#include <cstddef>
#include <iostream>
#include <string>

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
void change_value(T &value) {
    value += 42;
}

void set_string(std::string &value) {
    value = "changed";
}

template<typename T>
void print_value(const T& value) {
    std::cout << value << " ";
}
