/*
    Characteristics of Friend Function-
        2.  Overloading of Operators as a friend function-
            +1 arg is passed in friend fn than noraml overlading member function
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
            a=x, b=y;
        }
        void show()
        {
            cout<<a<<", "<<b<<endl;
        }
        /*
        Normal overloading-
        1 arg is passed
        Complex operator+ (Complex c)
        {
            Complex temp;
            //temp ke a mein c1.a+c2.a
            //c1  caller object hai to uska a direct accesible
            temp.a= a + c.a;
            temp.b= b+ c.b;
            return temp;
        }
        */
        friend Complex operator+(Complex, Complex);
};
//as a friend function 2 agr is paased
Complex operator+(Complex x, Complex y)
{
    Complex temp;
    temp.a= x.a+y.a;
    temp.b=x.b + y.b;
    return temp;
}

int main()
{
    Complex c1,c2;
    c1.set(3,4);
    c2.set(4,5);
    Complex c3;

   //Noraml Overloading=> c3= c1+c2;  //c3=c1.operator(c2)
   // c3.show();


    return 0;
}