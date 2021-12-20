//
// Created by eldarian on 20.12.2021.
//

#ifndef ALGCPP_QUICKSORT_H
#define ALGCPP_QUICKSORT_H

#include "Sort.h"

#include "cstdio"

template<class T>
class QuickSort : public Sort<T> {
protected:
    const char *name() override {
        return "QuickSort";
    }

    int partition(T *A, int low, int high) {
        T pivot = A[high];
        int i = low;
        for (int j = low; j < high; ++j) {
            if (A[j] <= pivot) {
                std::swap(A[i], A[j]);
                ++i;
            }
        }
        std::swap(A[i], A[high]);
        return i;
    }

    void quickSort(T *A, int low, int high) {
        if (low < high) {
            int p = partition(A, low, high);
            quickSort(A, low, p - 1);
            quickSort(A, p + 1, high);
        }
    }

    void sort(T *arr, int n) override {
        quickSort(arr, 0, n - 1);
    }

};

#endif //ALGCPP_QUICKSORT_H
