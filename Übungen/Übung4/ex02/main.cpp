#include <iostream>
#include <vector>

template<class T>
void print(T x) 
{
    std::cout << x << "\n";
}

template<class T> 
void print(std::vector<T> v) 
{
    for (T ele : v)
        std::cout << ele << " ";
    std::cout << "\n";
}


int main() {
    print(8);
    print("Hello");
    print(1.2);
    print(std::vector<float>{1.2,0.1,-9});
}
