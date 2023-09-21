#include<bits/stdc++.h>
using namespace std;

int solve(int index, int arr[], int n, vector<int> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
        return dp[index];

    int pick = solve(index + 2, arr, n, dp) + arr[index];
    int not_pick = solve(index + 1, arr, n, dp);
    return dp[index] = max(pick, not_pick);
}
int main()
{
    int arr[] = {9, 10, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = 0, sum = 0;
    vector<int> dp(n + 1, -1);
    cout << solve(index, arr, n ,dp);
    return 0;
}