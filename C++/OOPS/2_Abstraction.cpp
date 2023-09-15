#include<bits/stdc++.h>
using namespace std;
 


/*
    4.Abstraction-
        a.  Implementation Hiding
        b.  display only essential information
        ______________________________________________
        Types-
            1. Data Abstraction-
                This type only shows the required
                information about the data and hides the unnecessary data.
            2.  Control Abstraction-
                 This type only shows the required information about the 
                 implementation and hides unnecessary information.
        ______________________________________________
        How to acheive this?
            1.Abstraction using Classes
                A Class can decide which data member will be visible to
                 the outside world and which is not. 
                 ------------------------------------------------
            2.Abstraction in Header files
                Whenever we need to calculate the power of a number
                ,we simply call the function pow() present in the math.h 
                header file and pass the numbers as arguments without knowing
                the underlying algorithm according to which the function is
                actually calculating the power of numbers.
                ---------------------------------------------------------
            3.Abstraction using Access Specifiers
                a. Members declared as public in a class can be accessed from anywhere in the program.
                b. Members declared as private in a class, can be accessed only from within the class. 
                They are not allowed to be accessed from any part of the code outside the class.
        _________________________________________________
        Advantages of Data Abstraction
                1. Helps the user to avoid writing the low-level code
                2.Avoids code duplication and increases reusability.
                3.Can change the internal implementation of the class independently without affecting the user.
                4.Helps to increase the security of an application or program as only important details are provided to the user.
                5.It reduces the complexity as well as the redundancy of the code, therefore increasing the readability.
*/    



class A
{
    private:
    //made 'a' & 'b' unaccessible) from
    // the outside world.
        int a;
        int b;
    public:
        void set(int x, int y){
            a=x,b=y;
        }
        void display(){
            cout<<a<<", "<<b<<endl;
        }
};

int main()
{
    A obj;
    obj.set(9,6);
    obj.display();
    return 0;
}