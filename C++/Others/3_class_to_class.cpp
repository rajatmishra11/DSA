/*
    Class type to another Class Type-
        1. conversion through constructor.;
        2.  conversion through casting opeartor.
    ------------------------------------------
    Item i1;
    Product p1;
    p1.setdata(3, 4);
    i1= p1;                       //error
*/

#include <iostream>
using namespace std;

class Product
{
private:
    int m, n;

public:
    void set(int x, int y)
    {
        m = x;
        n = y;
    }
    int getm()
    {
        return m;
    }
    int getn()
    {
        return n;
    }
};

class Item
{
private:
    int a, b;

public:
    Item() {}
    Item(Product p)
    {
        a = p.getm();
        b = p.getn();
    }
    void show()
    {
        cout << a << ", " << b;
    }
};

int main()
{
    Item i1;

    Product p1;
    p1.set(7, 1);

    // i1=p1;  error use one of method 1. left wale ke liye constructor banao
    i1 = p1;
    i1.show();

    return 0;
}