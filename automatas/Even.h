//
// Created by eldarian on 09.05.2021.
//

#ifndef ALGCPP_EVEN_H
#define ALGCPP_EVEN_H

#include "Automata.h"

class Even : public Automata<int, bool, int> {
public:
    Even() : Automata(0) {}

protected:
    int f(int q, int x) override {
        return q + x;
    }

    bool w(int q, int x) override {
        return (q + x) % 2 == 0;
    }
};

#endif //ALGCPP_EVEN_H
