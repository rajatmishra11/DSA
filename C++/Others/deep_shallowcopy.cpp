/*
How do we copy data-
    1.  Calling Copy Constructor
    2.  Implicit Copy Assignment Opearator.
-----------------------------------------------
Shallow Copy-
    craeting copy of objects by copying data of all member 
    variables as it is.
------------------------------------------------
Deep Copy-
    Craeting an object by copying data of another object with the
    values along with the values of memory resources resides outside
    the object but handled by that object. 
*/

#include<conio.h>
#include <iostream>
using namespace std;

class Demo
{
    private:
        int a,b;
        int *p;
    public:
        void set(int x, int y, int z)
        {
            a=x, b=y, *p=z;
        }
        void show()
        {
            cout<<a<<","<<b<<","<<*p<<endl;
        }
        Demo()
        {
            p = new int;
        }

        //kaise bna hoga 
        // Demo(Demo &d)
        // {   
        //     //shallow copy
        //     a=d.a;
        //     b=d.b;
        //     p=d.p;    //pointer meimn copy dangerous , resouce same ( pointing same memory block of 5)
        // }

        Demo(Demo &d)
        {
            a=d.a;
            b=d.b;
            //deep copy
            //different memory addresses
            p= new int;
            *p  = *(d.p);
        }

      ~Demo()
      {
            delete p;
      }  
      //let d1 aur d2 agr shallow copy bnate to ek destructor call pe ek object (d1)delete hota
      //pointer p par 5 ki memory free kar deta.
      //aur phir d2 pointer invalid address ko point krta-> (p ek Dangling Pointer ho jaata)
};

int main()
{

    Demo d1;
    d1.set(2,7,5);
    //object banate waqt initialize kar rhe hai->
    Demo d2=d1;  //1.copy constructor called
    d1.show();
    d2.show();


    Demo d3;
    //next step mein kar rhe hai->
    d3=d2;      //2. Implicit-assingment operator overloading by compiler
    d3.show();  

    return 0;
}