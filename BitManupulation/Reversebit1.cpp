#include<bits/stdc++.h>
using namespace std;
 
//(11)10 = (1011)2.
// After reversing the bits we get:
// (1101)2 = (13)10.
int solve(int n){

    int flag=0;  //batega  1 mila ki nahi
    int rev=0;
    int j=0;
    //32 bit ka hota hai
    for(int i=31; i>=0; i--){
        //pahela mask 100...(32 digit) ka
        //ith mask hoga 
        int mask =(1<<i);

        if(flag){
            if((n& mask)!=0){
               // cout<<'1';
                int smask=(1<<j);
                rev|=smask;
            }
            else{
                //cout<<'0';
            }
            j++;
        }
        else{
            if((n & mask)!=0){
                flag=1;
               // cout<<'1';
                int smask=(1<<j);
                rev |= smask;
                j++;
            }
            else{
               // cout<<'0';
            }
        }
    }
    return rev;
}

int main()
{
    int n;
    cin>>n;
    int ans=solve(n);
    cout<<ans;
    return 0;
}