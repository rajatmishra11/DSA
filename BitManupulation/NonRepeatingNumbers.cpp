#include<bits/stdc++.h>
using namespace std;
 //xor logic-> same  ^ same=0 else 1
//& logic-> 1 & 1=1 else 0

pair<int,int> ans(int *arr, int n){
           int xor1=0;
            
            for(int i=0; i<n ; i++){
                xor1^=arr[i];
            }
            int rightmost= xor1 & -xor1;
            int x=0,y=0;
            for(int i=0; i<n ; i++){
                int val=arr[i];
                if((val & rightmost)==0){
                    //bit zero rahi hogi
                    x^=val;
                }
                else{
                    y^=val;
                }
            }
            if(x<y){
                return {x,y};
            }
            else{
                return {y,x};
            }
}


int main()
{
    int arr[]={36, 50, 24, 56, 36, 24, 42, 50};
    int n=8;
    pair<int,int> res= ans(arr,n);
    cout<<res.first<<" "<<res.second;
    return 0;
}