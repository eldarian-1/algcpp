//
// Created by eldarian on 09.05.2021.
//

#ifndef ALGCPP_CONDUCTOR_H
#define ALGCPP_CONDUCTOR_H

#include "Automata.h"

class Conductor : public Automata<int, bool, int> {
private:
    const int COST = 5;

public:
    Conductor() : Automata(0) {}

protected:
    int f(int q, int x) override {
        return (q + x) % COST;
    }

    bool w(int q, int x) override {
        return (q + x) >= COST;
    }

};

#endif //ALGCPP_CONDUCTOR_H
