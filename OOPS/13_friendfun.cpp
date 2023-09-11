/*
    Overloading of unary operator via friend function-
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
        Noraml Overlaoding of - oprator -*No argument
        Complex operator-()
        {
            Complex temp;
            temp.a=-a;
            temp.b=-b;
            return temp;
        }
        */

       friend Complex operator-(Complex);
};   

Complex operator-(Complex c)
{
    Complex temp;
    temp.a= -c.a;
    temp.b= -c.b;
    return temp;
}


int main()
{
    Complex c1,c2;
    c1.set(3,4);
    c2= -c1; //c1.opeartor-()   
    c2.show();
   //Noraml Overloading=> c3= c1+c2;  //c3=c1.operator(c2)
   // c3.show();


    return 0;
}