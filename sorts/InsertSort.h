//
// Created by eldarian on 02.05.2021.
//

#ifndef ALGCPP_INSERTSORT_H
#define ALGCPP_INSERTSORT_H

#include "Sort.h"

#include "cstdio"

class InsertSort : public Sort {
protected:
    std::string name() override {
        return "InsertSort";
    }

    void sort(int *arr, int n) override {
        int key, temp;
        for (int i = 0; i < n - 1; ++i) {
            key = i + 1;
            temp = arr[key];
            for (int j = i + 1; j > 0; --j) {
                if (temp < arr[j - 1]) {
                    arr[j] = arr[j - 1];
                    key = j - 1;
                }
            }
            arr[key] = temp;
        }
    }

};

#endif //ALGCPP_INSERTSORT_H
