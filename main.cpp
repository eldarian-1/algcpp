#include <cstdio>

#include "Array.h"
#include "randomizers/IntRandomizer.h"
#include "sorts/InsertSort.h"
#include "sorts/MergeSort.h"
#include "sorts/QuickSort.h"
#include "automatas/Conductor.h"
#include "automatas/Even.h"
#include "EratostheneSieve.h"
#include "FractionOperations.h"
#include "Fibonachi.h"

void sortTest() {
    int size = 100, min = -100, max = 100;
    Randomizer<int> *randomizer = new IntRandomizer(min, max);
    Array<int> *arg = new Array<int>(size, randomizer);
    InsertSort<int>().execute(new Array(*arg));
    MergeSort<int>().execute(new Array(*arg));
    QuickSort<int>().execute(new Array(*arg));
}

void automataTest() {
    Even c;
    for(int i = 0; i < 20; ++i) {
        Pair<bool, int> p = c.F(1);
        std::printf("%d %d\n", p.y, p.q);
    }
    std::printf("\n");
}

void eratostheneTest() {
    BeginEnd arg(2, 101);
    EratostheneSieve().execute(&arg);
}

void fractionTest() {
    FractionArg arg("5 8/9", '/', "-6 7/9");
    FractionOperations().execute(&arg);
}

void fibonachiTest() {
    FibonachiArg a = {13, FibonachiType::RECURSION};
    FibonachiArg b = {13, FibonachiType::TAIL};
    FibonachiArg c = {13, FibonachiType::DYNAMIC};
    Fibonachi().execute(&a);
    Fibonachi().execute(&b);
    Fibonachi().execute(&c);
}

int main() {
    sortTest();
    automataTest();
    eratostheneTest();
    fractionTest();
    fibonachiTest();
    return 0;
}
