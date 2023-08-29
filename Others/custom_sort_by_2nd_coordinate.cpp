#include<bits/stdc++.h>
using namespace std;


 //custom data structure->(x,y,z coordinates)
class node{
    public:
        int x;
        int y;
        int z;
    public:
        node(){

        }
        node(int x, int y, int z){
            this->x=x;
            this->y=y;
            this->z=z;
        }
};

//custom sort
class my_sort:public node{
   public:
        my_sort(){
           // cout<<"hello";
        }
        bool cmp(node *a, node *b){
            return a->y > b->y;
        }
};

class print: public my_sort{
    public :
        print(node *a){
            cout<<a->x<<a->y<<a->z<<endl;
        }
};


int main()
{   
    node n1(2,0,5);
    node n2(3,1,5);
    my_sort obj;
    if( obj.cmp(&n1,&n2)==true){
        print obj2(&n1);
    }
    else{
        print obj2(&n2);
    }
    return 0;
}