/*
    Overloading of insertion and extraction operator;
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
       
        friend ostream& operator<<(ostream&, Complex);
        friend istream& operator>>(istream&, Complex&);
};   

ostream& operator<<(ostream &dout, Complex c)
{
    cout<<c.a<<"+ i"<<c.b<<endl;
    return (dout);
}

istream& operator>>(istream &din, Complex &c)
{
    cin>>c.a>>c.b;
    return (din);
}

int main()
{
    Complex c1,c2;
    // cin>>c1; //error or {    cin.operator>>(c1)  } or {  operator<<(cin, c1)     }
    cin>>c1;
    cout<<c1;
    return 0;
}