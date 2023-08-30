#include<bits/stdc++.h>
using namespace std;
 


long long maxProduct(vector<int> arr, int n) {
    long long ans=arr[0];
    long long mx=ans;
    long long mn=ans;
    for(int i=1; i<arr.size(); i++){
        if(arr[i]<0) swap(mn,mx);
        mx = max(static_cast<long long int>(arr[i]), arr[i] * mx);
        mn = min(static_cast<long long int>(arr[i]), arr[i] * mn);
        ans=max(ans, mx);
    }
    return ans;
}

int main()
{
    vector<int>arr={2,3,-3,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<maxProduct(arr,n);
    return 0;
}