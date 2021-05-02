//
// Created by eldarian on 02.05.2021.
//

#ifndef ALGCPP_ALGORITHM_H
#define ALGCPP_ALGORITHM_H

#include <string>
#include <cstdio>

template<class T>
class Algorithm {
protected:
    virtual std::string name() = 0;
    virtual void run(T arg) = 0;

public:
    void execute(T arg) {
        std::printf("%s\n", name().c_str());
        run(arg);
        std::printf("\n");
    }
};


#endif //ALGCPP_ALGORITHM_H
