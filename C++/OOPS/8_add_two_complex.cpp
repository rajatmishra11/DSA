#include<iostream>
using namespace std;

class Complex{
    private:
        int a;
        int b;
    public:
        void set(int,int);
        void show();
        Complex add(Complex c){
            Complex temp;
            //=c1.a + c2.a;
             temp.a= a+ c.a;
             temp.b= b+ c.b;
             return temp;
        }
        Complex operator+(Complex c);
        Complex operator-();
};

void Complex::set(int x, int y){
    a=x;
    b=y;
    
}
void  Complex::show(){
    cout<<a<<"+("<<b<<"i)"<<endl;
}

Complex Complex::operator+(Complex c) {
    Complex temp;
    temp.a = a + c.a;
    temp.b = b + c.b;
    return temp;
}

Complex Complex::operator-()
{
    Complex temp;
    temp.a= -a;
    temp.b= -b;
    return temp;
}

int main()
{
    Complex c1,c2,c3,c4;
    c1.set(2,3);
    c2.set(5,6);
    //1. function call by passing obj & returning obj
    c3=c1.add(c2);
     // c3=c1+c2; error
    //2. or by operator loading (+)
    c3.show();
    //to overload +(binary operator)
    c4=c1+c2;
    c4.show();
    //overload unary operator
    c4= -c4;
    c4.show();
    return 0;
}