/*
    Primitive type-
        keywords-
        int, char, float, double etc.
    Class Type-
        is any class you defined.
*/


/*
    Why conversion is required-

    Primitive to Primitive Type-
    int x= 4;
    float y;
    y=x;               //No Error- auto type convsersion.
    --------------------------------------------
    float y= 5.5;
    int x;
    x=y;              //No Error- auto type conversion.
    //data loss 5.5 became 5.
----------------=--------------------------------------------


    Primitive to Class Type-
    (can be implemented throug constructor).
    Complex c1;
    int x= 5;
    c1= x;              //Error - No automatic type conversion
*/

#include <iostream>
using namespace std;

class Complex
{
    private:
        int a,b;
    public:
        void set(int x, int y)
        {
           a=x, b=y;
        }
        void show()
        {
            cout<<a<<"+i"<<b<<endl;
        }
        Complex(){}
        Complex(int k)
        {
            a= k;
            b=0;
        }
};

int main()
{
    Complex c1;
    int x=5;
   // c1=x; //error
   //after making constructor
   c1=x;
    c1.show();


    return 0;
}