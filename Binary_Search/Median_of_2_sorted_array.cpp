
#include <bits/stdc++.h>
using namespace std;

double MedianOfArrays(vector<int> &a, vector<int> &b)
{
    // Your code goes here
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    if (n1 > n2)
        return MedianOfArrays(b, a);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 >= 1)
            l1 = a[mid1 - 1];
        if (mid2 >= 1)
            l2 = b[mid2 - 1];

        // possible soln->
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return -1;
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {5, 7, 8, 9};
    cout << MedianOfArrays(a, b);
    return 0;
}
