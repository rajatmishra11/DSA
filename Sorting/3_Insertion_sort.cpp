#include<bits/stdc++.h>
using namespace std;
 

//algo like deck of cards->
//pick one by one


void bubblesort(int *arr, int n){
    for(int i=0; i<n; i++){
        //picking one by one->(rounds)
        int key=arr[i];
        //counter ke aage se sab sorted hi honge->
        int j=i-1;
        while(j>=0 && arr[j]>key){
            //shift-> copy element to next postion
            arr[j+1]=arr[j];
            j--;
        }
        //sahi jagah daal do->
        //j ek position piche hai esliye +1 karo
        arr[j+1]=key;
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