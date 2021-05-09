//
// Created by eldarian on 09.05.2021.
//

#ifndef ALGCPP_RANDOMIZER_H
#define ALGCPP_RANDOMIZER_H

template<class T>
class Randomizer {
public:
    virtual T next() = 0;
};

#endif //ALGCPP_RANDOMIZER_H
