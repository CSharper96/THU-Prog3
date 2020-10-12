#include "add.h"
#include "mul.h"
#include <iostream>
using namespace std;

int main(int, char**) {
    int num = add( mul(8,2), 4 );
    cout << "Ergebnis = " << num;
    return num;
}
