//
// Created by eldarian on 09.05.2021.
//

#ifndef ALGCPP_AUTOMATA_H
#define ALGCPP_AUTOMATA_H

template<class Output, class State>
struct Pair {
    Output y;
    State q;
};

template<class Input, class Output, class State>
class Automata {
private:
    State active;

public:
    Automata(State state) : active(state) {}

protected:
    virtual State f(State q, Input x) = 0;
    virtual Output w(State q, Input x) = 0;

public:
    State f(Input x) {
        return f(active, x);
    }

    Output w(Input x) {
        return w(active, x);
    }

    Pair<Output, State> F(Input x) {
        Pair<Output, State> result;
        result.y = w(active, x);
        result.q = f(active, x);
        active = result.q;
        return  result;
    }

};

#endif //ALGCPP_AUTOMATA_H
