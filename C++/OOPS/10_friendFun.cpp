#include <bits/stdc++.h>
using namespace std;

/*
    Friend Function-
        1.  is not an member of class to which it is friend.
        2.  is declared in the class with friend keyword.
        3.  must be defined outside the class to which it is friend.
        4.  can access any member of the class to which it is a friend.
        5.  cant access members of the class directly.
        6.  it has no caller object.
        7.  should not be defined with membership label.
    ------------------------------------------------------------
*/

class Complex
{
private:
    int a, b;

public:
    void set(int x, int y)
    {
        a = x, b = y;
    }

    void get()
    {
        cout << a << ", " << b << endl;
    }

    friend void fun(Complex);
};

// Note- we dont use membership label(::)
void fun(Complex c)
{
    cout << "Sum is " << c.a + c.b << endl;
}

int main()
{
    Complex c1;
    c1.set(6, 7); // c1 is caller object
    // c1.fun();  //wrong   //friend function is called without caller object.
    fun(c1);
    return 0;
}