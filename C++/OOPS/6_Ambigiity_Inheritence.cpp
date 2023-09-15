#include<bits/stdc++.h>
using namespace std;
 
class A{
    public:
        void fn(){
            cout<<"Im function fn of A"<<endl;
        }
};

class B{
    public:
         void fn(){
            cout<<"Im function fn of B"<<endl;
        }
};

class C: public A, public B{
    public:
        C(){
            cout<<"C is called & I'm inheriting A & B"<<endl;
        }
};

int main()
{
    C obj;
  //  obj.fn();
 //error: request for member 'fn' is ambiguous obj.fn();
    
    //resolving via using scope resolution operator ( :: )
    obj.A  ::  fn();
    obj.B  ::  fn();
 
    return 0;
}