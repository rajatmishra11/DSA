#include<bits/stdc++.h>
using namespace std;
 

/*
    1.Encapsulation-> (INFO-HIDING)
        wrapping of data members & functions
        a) Fully Encapsulated-
            all Data Members are private- accesible only in same class
        b) Data Hiding, Secure
        c) if we want, we can make class READ ONLY
        d) unit-testing
*/

class Student{
    private:
        string name;
        int age;
        double height;
    public:
        void setter(int age, string name, double height){
            this->age=age;
            this->height=height;
            this->name=name;
        }
        int getAge(){
            return this->age;
        }
        double getheight(){
            return this->height;
        }
        string getName(){
            return this->name;
        }
};

int main()
{
    Student s1;
    s1.setter(19,"Divya",5.6);
    cout<<s1.getName()<<endl;
    cout<<s1.getAge()<<endl;
    cout<<s1.getheight()<<endl;;
    cout<<sizeof(s1);
    return 0;
}