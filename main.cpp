#include "sorts/InsertSort.h"
#include "sorts/MergeSort.h"

int main() {
    InsertSort().execute(SortArg(1000, 10000));
    MergeSort().execute(SortArg(1000, 10000));
    return 0;
}
