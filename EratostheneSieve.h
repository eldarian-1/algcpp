//
// Created by eldarian on 25.05.2021.
//

#ifndef ALGCPP_ERATOSTHENESIEVE_H
#define ALGCPP_ERATOSTHENESIEVE_H

#include "Algorithm.h"

struct BeginEnd {
    int begin;
    int end;

    BeginEnd(int begin, int end) {
        this->begin = begin;
        this->end = end;
    }

};

class EratostheneSieve : public Algorithm<BeginEnd> {
private:
    bool *create(int n) {
        bool *arr = new bool[n];
        for(int i = 0; i < n; ++i) {
            arr[i] = true;
        }
        return arr;
    }

    int fill(bool *arr, int n) {
        int o = 0;
        for(int i = 2; i < n + 2; ++i) {
            if(arr[i - 2]) {
                for(int j = 2 * i; j < n + 2; j += i) {
                    arr[j - 2] = false;
                    ++o;
                }
            }
        }
        return o;
    }

    void print(bool *arr, int begin, int end, int o) {
        std::cout << "Operations: " << o << "\n";
        for(int i = begin - 2; i < end; ++i) {
            if(arr[i]) {
                std::cout << (i + 2) << " ";
            }
        }
        std::cout << "\n";
    }

protected:
    const char *name() override {
        return "EratostheneSieve";
    }

    void run(BeginEnd *arg) override {
        bool *arr = create(arg->end - 1);
        int o = fill(arr, arg->end - 1);
        print(arr, arg->begin, arg->end - 1, o);
    }

};

#endif //ALGCPP_ERATOSTHENESIEVE_H
