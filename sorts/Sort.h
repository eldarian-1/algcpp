//
// Created by eldarian on 02.05.2021.
//

#ifndef ALGCPP_SORT_H
#define ALGCPP_SORT_H

#include <cstdlib>
#include <cstdio>

#include "../Algorithm.h"

struct SortArg {
    int* array;
    int size;

    SortArg(int* arr, int n) {
        array = arr;
        size = n;
    }

    SortArg(int size, int min, int max) {
        this->size = size;
        array = new int[size];
        int diff = max - min + 1;
        for(int i = 0; i < size; ++i)
            array[i] = std::rand() % diff + min;
    }
};

class Sort : public Algorithm<SortArg> {
protected:
    virtual void sort(int *arr, int n) = 0;

    void printArray(SortArg arg) {
        for(int i = 0; i < arg.size; ++i)
            printf("%d ", arg.array[i]);
        printf("\n");
    }

    void run(SortArg arg) {
        printArray(arg);
        sort(arg.array, arg.size);
        printArray(arg);
    }
};

#endif //ALGCPP_SORT_H
