//
// Created by eldarian on 09.05.2021.
//

#ifndef ALGCPP_ARRAY_H
#define ALGCPP_ARRAY_H

#include <iostream>

#include "randomizers/Randomizer.h"

template<class T>
struct Array {
    T* array;
    int size;

    Array(T* arr, int n) {
        array = arr;
        size = n;
    }

    Array(const Array &arg) {
        size = arg.size;
        array = new T[size];
        for(int i = 0; i < size; ++i)
            array[i] = arg.array[i];
    }

    Array(int size, Randomizer<T> *randomizer) {
        this->size = size;
        array = new int[size];
        for(int i = 0; i < size; ++i)
            array[i] = randomizer->next();
    }

    ~Array() {
        size = 0;
        delete[] array;
    }

    void print() {
        for(int i = 0; i < size; ++i)
            std::cout << array[i] << " ";
        std::cout << "\n";
    }
};

#endif //ALGCPP_ARRAY_H
