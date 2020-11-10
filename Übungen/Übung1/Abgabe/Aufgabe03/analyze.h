#ifndef _ANALYZE_H
#define _ANALYZE_H

int analyze(std::string input) {
    return input.length();
}

int analyze(long input) {
    std::string strInput = std::to_string(input);
    return strInput.length();
}

#endif
