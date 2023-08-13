#include<bits/stdc++.h>
using namespace std;
 

void bubblesort(int *arr, int n){
    //round one me last par largest sahi position par aaega
    for(int i=0; i<n; i++){
    //j-> 0 se n-i-1 tak jayega (n-i) se (n) tak already sorted honge
        for(int j=0; j<n-i; j++){
           if(arr[j]>arr[i]) swap(arr[i], arr[j]);
        }
    }
} 
int main()
{
    int arr[]={3,8,2,4,100,8,0,88, 98, 567};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}