/*  
    Why OOPS->
        1.solve real world problems,
        2.map real entities
        3.code readibliliy
        4.code reusability
f
    object- > entity ->instance of clss (HERO)
                       1. state/ prop.
                            name, health, level
                       2. behaviour
                            attack, defense , dancemove
                       
    class->
        user definded data type
        custom data-tpe

*/ 

#include<bits/stdc++.h>
using namespace std;
 

class Hero
{
private:
    /* Properties */
    char name[100];
    int health;
public:
    Hero(/* args */);
    ~Hero();
};


Hero::Hero(/* args */)
{
}

Hero::~Hero()
{
}


int main()
{
    Hero h1; //Hero type object
    //size of Hero
    cout<<sizeof(h1);
    //size of empty class is 1 byte alloctated
 
 
    return 0;
}