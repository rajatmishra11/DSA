#include<bits/stdc++.h>
using namespace std;
 


int police_catch_theif(char arr[], int k)
{
    int n = strlen(arr)-1;
    //storing indices of polices and theives->
    vector<int>arr1, arr2;
    int k1=0, k2=0;
    for(int i=0; i<n; i++)
    {
        if( arr[i]=='P')
        {
            arr1.push_back(i);
        }
        if( arr[i]=='T')
        {
            arr2.push_back(i);
        }
    }
    //arr1->police hai. 
    //arr2->theif hai.
    int count = 0, j = 0;
    for (int i = 0, j = 0; i < arr1.size() && j < arr2.size();)
    {
        if (abs(arr1[i] - arr2[j]) <= k)
        {
            count++;
            i++, j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    return count;
}

int main()
{
    char arr[]={'T', 'T', 'P', 'P', 'P', 'T', 'P'};
    int k=2;
    cout<< police_catch_theif(arr, k);
    return 0;
}