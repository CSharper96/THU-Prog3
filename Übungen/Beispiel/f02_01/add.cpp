#include <iostream>
void addLog(const char* s) {
    std::clog << s << "\n";
}

int add(int x, int y) {
    addLog("called mul.");
    return x+y;
}