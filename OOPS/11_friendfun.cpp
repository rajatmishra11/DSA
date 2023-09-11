/*
Chacteristics of friend function-
        1.  can become friend to more than one class. 
*/

#include<bits/stdc++.h>
using namespace std;
 

class B;
class A
{   
    private:
        int a;
    public:
    void setdata(int x) {
        a=x;
    }
    
    friend void fun(A,B);
};
class B
{   
    private:
        int b;
    public:
    void setdata(int x) {
        b=x;
    }
    
    friend void fun(A,B);
};

void fun(A o1, B o2)
{
    cout<<"sum is "<<o1.a+o2.b<<endl;
}

int main()
{

    A obj1;
    B obj2;
    obj1.setdata(9);
    obj2.setdata(5);
    fun(obj1, obj2);

 
 
    return 0;
}