#include <bits/stdc++.h>
using namespace std;

int rec(int idx, int wt[], int val[], int cap)
{
    if (idx == 0)
    {
        if (cap >= wt[0])
        {
            return val[0];
        }
        else
            return 0;
    }
    int take = 0;
    if (wt[idx] <= cap)
        take = val[idx] + rec(idx - 1, wt, val, cap - wt[idx]);
    int not_take = 0 + rec(idx - 1, wt, val, cap);
    return max(take, not_take);
}

int solve(int wt[], int val[], int cap, int n)
{
    return rec(n - 1, wt, val, cap);
}

int main()
{
    int wt[] = {1, 2, 4, 5};
    int val[] = {5, 4, 8, 6};
    int cap = 5;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << solve(wt, val, cap, n);
    return 0;
}