#include<iostream>
#include<string>
#include<cassert>
using namespace std;

// insert code here or create analyze.h/cpp
// (possible with <20 LOC)
//#include"analyze.cpp"

int main(int, char**) 
{  
    // count number of digits (incl. Sign) or chars  
    assert( analyze(0) == 1); // one digit  
    assert( analyze(9) == 1); // one digit  
    assert( analyze(-1) == 2); // one digit+1 char  
    assert( analyze(1234) == 4); // 4 digits  
    assert( analyze(-90) == 3); // 2 digits+1 char  
    assert( analyze("Hello World") == 11); // 11 chars  
    assert( analyze("ABC") == 3); // 3 chars
}

int analyze(const char* c)
{
    int counter = 0;
    while (c[counter] != '\0')
    {
        counter++;
    }
    return counter;
}
int analyze(string str)
{
    return (int)str.length();
}
int analyze(int input) {
    string strInput = to_string(input);
    return strInput.length();
}