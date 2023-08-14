#include<bits/stdc++.h>
using namespace std;
 

int count_set_bits(int n){
    int count=0;
    while(n){
        int rsbm= n& (-n);
        n=(n-rsbm);
        count++;
    }
    return count;
}

int main()
{
  int n;
  cin>>n;
  cout<<count_set_bits(n);
    return 0;
}