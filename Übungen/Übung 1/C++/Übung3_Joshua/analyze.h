#ifndef _ANALYZE_H
#define _ANALYZE_H
#include<string>
int analyze(std::string input) {
    return (int)input.length();
}

/*
The following function has been commented out
for when the function has been called, provided 
with a 0 as parameter, it couldn't decide which
overloaded funtion to use (long/char*)
*/
// int analyze(const char* input) {
//     std::string strInput = input;
//     return strInput.length();
// }

int analyze(long input) {
    std::string strInput = std::to_string(input);
    return (int)strInput.length();
}

#endif