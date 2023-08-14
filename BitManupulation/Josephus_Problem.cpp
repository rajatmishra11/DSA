#include<bits/stdc++.h>
using namespace std;
 

 //solution n can be expressed in terms of 2^x+l;
 //ans would be -> 2*l+1;



int powerof2(int n){
    int x=1;
    while(x*2 <= n){
        x*=25; 
    }
    return x;
}


int standard(int n){
    int hp_of_2= powerof2(n);
    int l= n- hp_of_2;
    return (2*l+1);
}

int main()
{
    int n;
    cin>>n;
    cout<< standard(n);
    return 0;
}