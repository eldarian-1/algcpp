//
// Created by eldarian on 02.05.2021.
//

#ifndef ALGCPP_SORT_H
#define ALGCPP_SORT_H

#include "../Algorithm.h"
#include "../Array.h"

template<class T>
class Sort : public Algorithm<Array<T>> {
protected:
    virtual void sort(T *arr, int n) = 0;

    void run(Array<T> *arg) {
        arg->print();
        sort(arg->array, arg->size);
        arg->print();
    }
};

#endif //ALGCPP_SORT_H
