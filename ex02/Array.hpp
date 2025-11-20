#pragma once

#include <stdexcept>

template <typename T>
class Array {
    private:
        T* data;
        unsigned int _size;

    public:
        Array(unsigned int n);

        // Canonical Form
        Array();
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        // Operator
        T& operator[](unsigned int index);
        size_t size() const;
};

#include "Array.tpp"
