#include<bits/stdc++.h>
using namespace std;
 

/*
    2.INHERITENCE->
        a)The capability of a class to derive properties
         and characteristics from another class is called Inheritance.
        b)Modes of Inheritance: There are 3 modes of inheritance.
            Public Mode: If we derive a subclass from a public base class. 
                    Then the public member of the base class will become public in the derived class 
                    and protected members of the base class will become protected in the derived class.
            Protected Mode: If we derive a subclass from a Protected base class.
                    Then both public members and protected members of the base class will become
                    protected in the derived class.
            Private Mode: If we derive a subclass from a Private base class.
                    Then both public members and protected members of the base class will become
                     Private in the derived class.

            class | mode
            public+ public= public
            public+ private= private
            public+ protected= protected

            protected+ public= protected
            protected+ private= private
            protected+ protected= protected

            private+ public= NA (NOT ACCESIBLE)
            private+ provate= NA
            private+ protected= NA
        c)Note: The private members in the base class cannot be directly accessed in the derived class,
         while protected members can be directly accessed.
*/


#include<iostream>
using namespace std;

class Human{
public:
    double height;
    double weight;
    int age;
public:
    void setter(double h, double w, int a){
        height=h;
        weight=w;
        age=a;
    }
    void getter(){
        cout<<height<<"ft, "<<weight<<"kg, "<<age<<"years"<<endl;
    }
};

class Male: public Human{
public:
    string color;
public:
    void setcolor(string s){
        color=s;
    }
    void prop(){
        cout<<"MALE IS SLEEPING, and I'm "<<color<<endl;
    }
};

class Female: protected Human{
public:
    string color;
public:
    void setcolor(string s){
        color=s;
    }
    void prop(){
        cout<<"FEMALE IS SLEEPING, and I'm "<<color<<endl;
    }
    void setter(double h, double w, int a){
        height=h;
        weight=w;
        age=a;
    }
    void getter(){
        cout<<height<<"ft, "<<weight<<"kg, "<<age<<"years"<<endl;
    }
};

int main()
{
//     Male m1;
//     m1.setter(5.8, 61, 23);
//     m1.setcolor("BLACK");
//     m1.getter();
//     m1.prop();
//     cout<< m1.age<<endl;
//     cout<< m1.height<<endl;

    Female m2;
    m2.setter(5.2, 55, 21);
    m2.setcolor("White");
    m2.getter();

    return 0;
}
