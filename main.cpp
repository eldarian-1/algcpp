#include "sorts/InsertSort.h"
#include "sorts/MergeSort.h"

int main() {
    InsertSort().execute(SortArg(10, -100, 100));
    MergeSort().execute(SortArg(10, -100, 100));
    return 0;
}
