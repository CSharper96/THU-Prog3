#include <iostream>
void mulLog(const char* s) {
    std::clog << s << "\n";
}

int mul(int x, int y) {
    mulLog("called add.");
    return x*y;
}
