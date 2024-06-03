#include <bits/stdc++.h>
using namespace std;

/*
______________________________________________________________________________________________
   Polymorphism-
       1.polymorphism as the ability of a message to be displayed in more than one form.
       2. means having many forms.
   Types-
       1. Compile Time Polymorphism
       2. Run Time Polymorphism
______________________________________________________________________________________________
   1.Compile Time Polymorphism (Static)
       a) Function Overloading-
                   Functions can be overloaded by changing the number of arguments or/and
                   changing the type of arguments.
       --------------------------------------------------------------------------------------
       b) Operator Overloading- (change the working of operator)
                   C++ has the ability to provide the operators with a special meaning for a data type,
                   this ability is known as operator overloading. For example,
                   we can make use of the addition operator (+) for string class to concatenate two strings.
                   We know that the task of this operator is to add two operands. So a single operator ‘+’,
                   when placed between integer operands, adds them and when placed between string operands, concatenates them.
_______________________________________________________________________________________________
*/

/* ex-Function Overloading-
class A
    {
        public:
            void sayHello(){
                cout<<"A is chanting :Jai shree Ram"<<endl;
            }
            void sayHello(string name){
                cout<<name<<" is chanting :Har Har Mahadev"<<endl;
            }
            void add(int x, int y, int z){
                cout<<"IM 3 operator func, ans is "<<x+y+z<<endl;
            }
            void add(int x, int y){
                cout<<"IM 2 operator func, ans is "<<x+y<<endl;
            }
    };

int main()
    {
        A obj;
        obj.sayHello();
        obj.sayHello("Rajat");
        obj.add(2,3,4);
        obj.add(4,8);
        return 0;
    }
*/

/* ex-Operator Overloading
class B
{
    public:
        int a;
        int b;
    public:
        int add()
        {
            return a+b;
        }
    //overloading +
    void operator+ (B &obj)
        {
            int val1 = this->a;
            int val2 = obj.a;
            cout<<(val1-val2)<<endl;
        }
    //overloading ()
    void operator() ()
        {
            cout<<"I'm () & i'm overloded"<<endl;
        }
};


int main(){
    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj1 + obj2;
    obj1();
    return 0;
}
*/
/*
________________________________________________________________________________________________________________________
    2. Runtime Polymorphism-
        Late binding and dynamic polymorphism are other names for runtime polymorphism.
        The function call is resolved at runtime in runtime polymorphism.

        -------------------------------------------------------------------------------
        Types->
            a) Function Overriding:
                occurs when a derived class has a definition for one
                of the member functions of the base class.
                That base function is said to be overridden.
                --------------------------------------------------
            b)  Virtual Funtion:
                is a member funtion that is declared in the base class using keyword (virtual)
                and is re- defined (overridden)  in derived class

                Key Points-
                    1.VF- are dynamic in nature
                    2.VF- called during runtime

___________________________________________________________________________________________________________________________
*/

/* ------------------------------------------------------------------------------------------------
ex- a).Function Overriding
class Animal
    {
        public:
            void speak(){
                cout<<"speaking\n";
            }
    };

class Dog: public Animal
    {
        public:
            void speak(){
                cout<<"barking\n";
            }
    };


int main()
    {
        Dog obj;
        obj.speak();
        return 0;
    }
*/

/*

--------------------------------------------------------------------------------------------------------------
b) Virtual Function    (LATE - BINDING)
class A
    {
        public:
           virtual void  show(){
                cout<<"Base class A\n";
            }
    };

class B: public A
    {
        public:
            void  show(){
                cout<<"Child class B\n";
            }

    };


int main(){
//1.
    // B obj;
    // obj.show();
    // o/p- "Child class B"
//2.--------------------------
    // A *bptr; //pointer of base class
    // A aa;    //obj of base class
    // bptr=&aa;
    // bptr->show();
    // o/p - "Base class A\n";
//3-----------------------------
    // A *bptr;
    // B aa;     //obj of child class
    // bptr=&aa;
    // bptr->show();
    //o/p - *("Base class A") !!!!???
//4---------------------------------
    //*** after using virtual keyword in A class
    //Late Binding
    A *bptr;
    B aa;     //obj of child class
    bptr=&aa;
    bptr->show();
    //o/p- "Child class B"

}
___________________________________________________________________________________________
//Pure Virtual Function
    Abstract Class-
        1.  A class containing  at least one pure virtual function is an abstract class.
        2.  We can not instantiate abstract class
        3.  we must override that function in the derived class, otherwise,
            the derived class will also become an abstract class.
        4.  A pure virtual function is declared by
            assigning 0 in the declaration.
        5. An abstract class can have constructors.
___________________________________________________________________________________________
*/
class Person
{
public:
    virtual void fun() = 0; // pure virtual fn
    void f1() {}
};

class Student : public Person
{
public:
    void fun()
    {
        cout << "fun() is called\n";
    }
};

int main()
{
    Student d;
    d.fun();
}
