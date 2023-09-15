#include<bits/stdc++.h>
using namespace std;
/*
Static Member Variable-
    1.  Declared inside class body
    2.  also known as class member variable
    3.  They Must be defined outside the class
    4.  doesn't belong to any object, but to the whole class
    5.  there will be only one copy of static member variable for the whole class
    6.  any object can use same copy of class varible
    7.  They can be used with class name
--------------------------------------------------------------------
Static Member Function-
    1.  They are Qualified with the keyword static.
    2.  they are also called clas  member function 
    3.  invoked with or without object
    4.  can only access static members of class.
*/



class Account
{
    private:
        int balance;        //instance variable
        static float roi;   //Static Member Variable/ Class Variable 
    public:
        void setBalance(int b)
        {
            balance=b;
        }

        static void setRoi(float r)   ///static member function
        {
            roi=r;
        }
};



//defining outside of class
float Account:: roi= 3.5f;

int main()
{

    Account a1,a2;
    // Account::roi=4.5; cannot assingened due to private member
    a1.setRoi(6.5f);
    return 0;
}