#include <iostream>

//Definieren Sie eine Klasse A, die nicht kopierbar, aber verschiebbar ist.
class A
{
    A *ptr = nullptr;
    //nicht kopierbar
    //copy-constructor
    A(const A &) = delete;
    //copy-operator
    A &operator=(const A &) = delete;

    //verschiebbar
    //verschiebbar -> move constructor
    A(A &&other) {}

    //verschiebbar -> move operator
    A &operator=(A &&other)
    {
        if (&other != this)
        {
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};

//Definieren Sie eine Klasse B die nicht kopierbar und nicht verschiebbar ist.
class B
{
    //nicht kopierbar
    //copy-constructor
    B(const B &) = delete;
    //copy-operator
    B &operator=(const B &) = delete;

    //Gibt es keine selbsterstellten move-Constructor, -Operator, wird beim move-Aufruf, copy verwendet.
    //Da aber das Kopieren unterbunden ist, sind Objekte von B automatisch auch nicht verschiebbar.
};

int main()
{
}
