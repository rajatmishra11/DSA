#include <bits/stdc++.h>
using namespace std;

/*
    Every row in matrix is sorted.
*/
// User function template for C++

class Solution
{
public:
    int lower_bound(vector<int> mat, int n, int m)
    {
        int key = 1;
        int low = 0;
        int high = m - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mat[mid] == key)
            {
                ans = mid;
                high = mid - 1;
            }
            else if (mat[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int ans = -1, count1 = 0, maxcount = 0;
        // if not present
        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(arr[i], n, m);
            if (idx == -1)
                continue;
            else
            {
                count1 = m - idx;
                if (count1 > maxcount)
                {
                    maxcount = count1;
                    ans = i;
                }
            }
            // cout<< count1<<", "<<maxcount<<endl;
        }
        return ans;
    }
};

int main()
{

    return 0;
}