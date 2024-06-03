#include<bits/stdc++.h>
using namespace std;
 

int solve( int i, int target, int arr[])
{
    if(i<=0)
    {
        if(target==0)
        {  
            return 1;
        }
        else return 0;
    }
    int take=solve(i-1, target-arr[i], arr);
    int nottake= solve(i-1, target, arr);
    return take+nottake;
}

int main()
{
int arr[]={9,7,9,2,4,10};
int target=16;
int size=6;
int count=0;
cout<<solve(size-1, target, arr); 
    return 0;
}