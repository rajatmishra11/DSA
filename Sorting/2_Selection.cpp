#include<bits/stdc++.h>
using namespace std;
 




void Selection_sort(int *arr, int n){
    for(int i=0; i<n; i++){
       // int mini=arr[i];
       //ith ko mini ele maan lo
        int mini_idx=i;
        for(int j=i+1; j<n; j++){
            //check karo aage koi ele hai jo mini ele se chota hai
            if(arr[mini_idx] > arr[j]){
                //agar hai to mini idx daal do
                mini_idx=j;
            }
        }
        //mini apni sahi jagah daal do
        swap(arr[mini_idx], arr[i]);
    }
} 

int main()
{
    int arr[]={3,8,2,4,100,8,0,88, 98, 567};
    int n=sizeof(arr)/sizeof(arr[0]);
    Selection_sort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}