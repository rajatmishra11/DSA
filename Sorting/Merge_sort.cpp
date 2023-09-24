#include<bits/stdc++.h>
using namespace std;
//algo->divide & conquer  ->(fast)
//1) Divide -> via mid
//   *we need low index and high index;
//   *recursive call karo (mid se pahele tak  aur mid ke baad tak)


//2)  *merge ki call aaegi divide ke baad 
//    *merge two sorted array algo
//    *we have to create two array copy of length (low to mid) & (mid+1 to high);
//    *copying values of two arrays(simple)


void merge(int low, int high, int *arr){
    int mid = (low+high)/2; 
    int len1= (mid-low+1);
    int len2= (high-mid);
    //create 2 array dynamically
    int *first= new int[len1];
    int *second= new int[len2];
    //copying value
    int k=low;
    for(int i=0; i<len1; i++){
        first[i]=arr[k];
        k++;
    }

    k=mid+1;
    for(int i=0; i<len2; i++){
        second[i]=arr[k];
        k++;
    }

    //merge  2 sorted array
    int index1=0;   
    int index2=0;
    k= low;  //main array index

    while(index1< len1 && index2< len2){
        if(first[index1] < second[index2]){
            arr[k]=first[index1];
            k++; index1++;
        }
        else {
            arr[k]=second[index2];
            k++, index2++;
        }
    }

    //kisi 1 ki length jyada ho
    while (index1< len1)
    {
        arr[k]=first[index1];
        k++, index1++;
    }

     while (index2< len2)
    {
        arr[k]=second[index2];
        k++, index2++;
    }
    
}

void divide(int low ,int high, int *arr){
    //base case ->
    if(low>=high) return;
    //calculate mid
    int mid=(high+low)/2;
    //left call
    divide(low, mid ,arr);
    //right call
    divide(mid+1, high, arr);
    //merge
    merge(low, high, arr);
}





int main()
{
 
 int arr[]={38,27,43,3,9,82,10};
 int n=sizeof(arr)/sizeof(arr[0]);
 divide(0, n-1, arr);
 n=sizeof(arr)/sizeof(arr[0]);
cout<<"final sorted array"<<endl;
 for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
 }
    return 0;
}