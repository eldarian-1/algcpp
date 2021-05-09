//
// Created by eldarian on 09.05.2021.
//

#ifndef ALGCPP_INTRANDOMIZER_H
#define ALGCPP_INTRANDOMIZER_H

#include "Randomizer.h"

#include <cstdlib>

class IntRandomizer : public Randomizer<int> {
private:
    int min, max;

public:
    IntRandomizer(int min, int max) : min(min), max(max) {}

    virtual int next() override {
        return std::rand() % (max - min + 1) + min;
    }
};

#endif //ALGCPP_INTRANDOMIZER_H
