#include<bits/stdc++.h>
using namespace std;
//kadanes algo-> max sum subarray->


    int maxOnes(int a[], int n)
    {
        int count1=0;
        for(int i=0; i<n; i++){
            if(a[i]==1){
                count1++;
                a[i]=-1;
            }
            else{
                a[i]=1;
            }
        }
        
        //count1->ones
       // cout<<count1<<endl;
        
        //kadanes algo->
        int max_sum=INT_MIN;
        int curr_sum=0;
        for(int i=0; i<n; i++){
            curr_sum+= a[i];
            max_sum=max(curr_sum, max_sum);
            curr_sum=max(curr_sum, 0);
        }
        if(max_sum<0) max_sum=0;
        return count1+max_sum; 
    }

int main()
{  
  
   int n = 7;
   int arr[] = {1, 0, 0, 1, 0, 0, 1};
    cout<< maxOnes(arr,n);
    return 0;
}