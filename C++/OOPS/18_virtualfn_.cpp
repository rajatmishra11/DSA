#include<bits/stdc++.h>
using namespace std;


/*
Base Class Pointer -
    1.  Base Class Pointer can point to the object of any class
        of its descendant class.
    2.  but it's converse is not true. 

*/


class A
{
    public:
        void f1()
        {
            cout<<"Mai A ka f1 Hun"<<endl;
        }
        void f2()
        {
            cout << "Mai A ka f2 Hun" << endl;
        }
};

class B:    public A
{
    public:
        void f1()   
        {
            //method overriding -> same protype
            cout<<"Mai B ka f1 hun"<<endl;
        }
        void f2(int x)
        {
            //method hiding-> same name- but different arg.
            cout << "Mai B ka f2 Hun" << endl;
        }
        
};


int main()
{

 A *ptr;
 B obj;
 obj.f1();    //early binding by compiler
//obj.f2();    //B pe jaaegya -> error (arg nhi diya hai)
 ptr = &obj;
 obj.f1();
 obj.f2();
 obj.f2(9);
 
    return 0;
}