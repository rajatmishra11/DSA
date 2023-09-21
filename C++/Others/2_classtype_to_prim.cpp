/*
    ClasType to Primitive type-
        can be implemented with casting operator.

        operator type()
        {


            return (type-data);
        }

--------------------------------------
    Complex c1;
    c1.set(3,6);
    int x;
    x=c1;                      //error!
*/

#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
    void show()
    {
        cout << a << "+i" << b << endl;
    }

    operator int()
    {
        return (a);
    }
};

int main()
{
    Complex c1;
    c1.set(6,9);
    c1.show();
    int x;
    x=c1;
    cout<<"x is equal to  "<<x;
    return 0;
}