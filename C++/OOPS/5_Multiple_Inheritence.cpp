#include<bits/stdc++.h>
using namespace std;
 

 
class Animal{
    public:
        int age;
        int weight;
    public:
        void setter(int age, int weight){
            this->age=age;
            this->weight=weight;
        }
        void getter(){
            cout<<age<<"years, "<<weight<<"kg"<<endl;
        }
        void bark(){
            cout<<"One of the Animal is Dog, can Bark"<<endl;
        }
};


class Dog: public Animal{

};

class GermanShepherd:public Dog{
    public:
    GermanShepherd(){
        cout<<"I'm German Dog"<<endl;
    }
};


//multiple 

class  Human{
    public:
        int color;
    public:
        void speak(){
            cout<<"I'm human and I can Speak English"<<endl;
        }
};

class Hybrid: public Animal, public Human{

};

int main()
{

 GermanShepherd g1;
 g1.setter(7,18);
 g1.getter();

Hybrid h1;
h1.bark();
h1.speak();

    return 0;
}