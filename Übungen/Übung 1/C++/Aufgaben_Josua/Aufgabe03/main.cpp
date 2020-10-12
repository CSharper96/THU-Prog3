#include <iostream>
#include <cassert>
#include "analyze.h"

int main(int, char**) {
    assert(analyze(0) == 1);
    assert(analyze(9) == 1);
    assert(analyze(-1) == 2);
    assert(analyze(1234) == 4);
    assert(analyze(-90) == 3);
    assert(analyze("Hello World") == 11);
    assert(analyze("ABC") == 3);
}
