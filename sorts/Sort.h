//
// Created by eldarian on 02.05.2021.
//

#ifndef ALGCPP_SORT_H
#define ALGCPP_SORT_H

#include <cstdlib>
#include <cstdio>

#include "../Algorithm.h"

struct SortArg {
    int size, max;
    SortArg(int size, int max) {
        this->size = size;
        this->max = max;
    }
};

class Sort : public Algorithm<SortArg> {
private:
    int n;
    int *arr;

protected:
    virtual void sort(int *arr, int n) = 0;

    void createArray(SortArg arg) {
        n = arg.size;
        arr = new int[n];
        for(int i = 0; i < n; ++i)
            arr[i] = std::rand() % arg.max;
    }

    void printArray() {
        for(int i = 0; i < n; ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }

    void cleanArray() {
        n = 0;
        delete[] arr;
    }

    void run(SortArg arg) override {
        createArray(arg);
        printArray();
        sort(arr, n);
        printArray();
        cleanArray();
    }

};

#endif //ALGCPP_SORT_H
