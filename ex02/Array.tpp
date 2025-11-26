#include "Array.hpp"

template <typename T>
Array<T>::Array(unsigned int n)
    : _size(n)
{
    if (_size == 0) {
        _data = nullptr;
        return;
    }
    _data = new T[n];
    for (size_t i = 0; i < n; i++) {
        _data[i] = T();
    }
}

template <typename T>
Array<T>::Array()
    : _data(nullptr), _size(0)
{
}

template <typename T>
Array<T>::Array(const Array& other) {
    if (this != &other) {
        _size = other._size;
        if (_size == 0) {
            _data = nullptr;
            return;
        }
        _data = new T[_size];
        for (size_t i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        _size = other._size;
        if (_size == 0) {
            _data = nullptr;
            return *this;
        }
        _data = new T[_size];
        for (size_t i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
     if (index >= _size || _size == 0) {
        throw std::out_of_range("Index out of range");
    }
    return _data[index];
}

template <typename T>
size_t Array<T>::size() const {
    return _size;
}
