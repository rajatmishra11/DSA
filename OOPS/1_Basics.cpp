/*  
BASICS OF OOPS-
    -------------------------------------------------------
    Difference b/w Structure and Class in C++
        The Only Difference is-
            -members of structre are public by default.
            -members of class are private by default.
    --------------------------------------------------------       
    Why OOPS->
        1.solve real world problems,
        2.map real entities
        3.code readibliliy
        4.code reusability
    --------------------------------------------------------
    object- > entity ->instance of class 
                       1. state/ prop.
                            name, health, level
                       2. behaviour
                            attack, defense , dancemove
    --------------------------------------------------------
    class->
        1.  user definded data type
        2.  custom data-tpe
    -------------------------------------------------------
    What is Constructor-
        1.  Member Function of class
        2.  name same as class name
        3.  has no return type, no use of return keyword
        4.  must be an instance member function, that is, is cannot be static.
        5.  is imnplicitly invoked/called when an objects is created
        6.  is used to solve the problem of intitialsation.
    -----------------------------------------------------------------------------
    What is The problem of initailisaton-
        1.  Why it is called Constructor.
        2.  What is the Problem of Intilaisation.
        3. How Constructor resolves this issue.
    -----------------------------------------------------------------------------
    What is Destructor-
        1. is instance member function of a class.
        2.  name of destructor is same as the name of a class
            but predictate by (~) symbol.
        3.  never be static.
        4.  no return type
        5.  takes no argument( No overloading is possible)
        6.  is invoked implicitly when object is going to destroy.
        7.  it should be definded/coded to realease resourses allocated to an object.
*/ 


#include<bits/stdc++.h>
using namespace std;
 

class Complex
{
    private:
        int a=0, b=0;
    public:
        //constructor overloading-
        Complex(int x, int y){
            //cout<<"Hello i.m ist Constructor .. im invoked"<<endl;
            a=x, b=y;
        }
        Complex(int x){
            //cout<<"Hello i.m 2nd Constructor .. im invoked"<<endl;
            a=x;
        }
        //default constructor
        Complex(){}
        //Copy Constructor
        Complex(Complex &c){
            a= c.a;
            b= c.b;
        }
        void show();

        //destructor
        ~ Complex(){

        }
};


void Complex::show(){
     cout<<a<<"+i"<<b<<endl;
}

int main()
{
    Complex c1(3,4);
    c1.show();
    //or Complex c1= Complex(3,4) same


    Complex c2(6);
    c2.show();
    //for single value Complex c2=6 same


    Complex c3;  //default
    c3.show();


    Complex c4=c1;  
    //or Complex c4(c1) same;
    /*
        Which Constructor is called-
            No-one, then why not error?
        if there is no Constructor in class then, 
        Compiler created two constructor
            1. Defalut Constructor-
            2. Copy Constructor-
        In here, we created Constructor ,then Default will not made by Compiler,
        therefor, Compiler make Copy Constructor

        How To make Copy by ourself;
        -use reference of object of same class
    */
   c4.show();
    return 0;
}



