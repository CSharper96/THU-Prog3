#include "List.h"

int main(int argc, char** argv) {
    ArbitraryList <std::string>l;
    l.insert_front("1");
    l.insert_front("2");
    l.insert_front("3");
    l.insert_front("4");
    l.print_all();
    
    ArbitraryList <std::string>l2{"5","6","7","8"};
    // l2.print_all();

    ArbitraryList <std::string> l3 = l;
    l3.print_all();
    l3 = l2;
    l3.print_all();
    

}

