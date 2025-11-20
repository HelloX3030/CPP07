#include "Array.hpp"

template <typename T>
Array<T>::Array(unsigned int n)
    : size(n)
{
    if (size == 0) {
        data = nullptr;
        return;
    }
    data = new T[n];
    for (size_t i = 0; i < n; i++) {
        data[i] = T();
    }
}

template <typename T>
Array<T>::Array()
    : data(nullptr), size(0)
{
}

template <typename T>
Array<T>::Array(const Array& other) {
    if (this != &other) {
        size = other.size;
        if (size == 0) {
            data = nullptr;
            return;
        }
        data = new T[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        size = other.size;
        if (size == 0) {
            data = nullptr;
            return *this;
        }
        data = new T[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}
