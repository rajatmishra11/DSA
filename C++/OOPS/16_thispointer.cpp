/*
    Object Pointer-
        A pointer conatins address of an object.
    -------------------------------------------
    this pointer-
        -   this is a local object pointer in  every instance
         member function containing address of the caller object.
        -   this pointer can not be empty.
        -   it is used to refer caller object in member function.
*/

#include <iostream>
using namespace std;

class Box
{
private:
    int l, b, h;

public:
    void set(int l, int b, int h)
    {
        this->l = l;
        this->b = b;
        this->h = h;
    }
    void get()
    {
        cout << "l, b, h are " << l << ", " << b << ", " << h << endl;
    }
    void getVolume()
    {
        cout << l * b * h << endl;
    }
};

int main()
{
    Box smallbox;
    Box *p; // object pointer p
    p = &smallbox;

    // p.set(2,4,8);  error:  error: request for member 'set' in 'p',
    //                 which is of pointer type 'Box*' (maybe you meant to use '->' ?)
    // p.get();
    p->set(3, 1, 9);
    p->get();
    p->getVolume();

    return 0;
}