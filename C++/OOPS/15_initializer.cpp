/*
    INITIALIZER-
        1.  Initializer List is used to initialize data members of a class
        2.  The list of members to be initialzed  is indicated with a
            constructor as a comma seprated list followed by a colon;
        3. There are situatons where intialization of data members inside constructor
            doesn't work and initializer List must be used.
            -For intialization of non-static const data members.
            -For intialization of reference members.
*/
#include <conio.h>
#include <iostream>
using namespace std;

class Dummy
{
private:
    int a, b;
    const int x;
    int &y;
    // const int x=5;  wrong
public:
    Dummy(int &n) : x(5), y(n)
    {
    }
};

int main()
{
    int m = 6;
    Dummy d1(m);
    return 0;
}