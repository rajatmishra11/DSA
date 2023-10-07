#include <bits/stdc++.h>
using namespace std;
/*
int f(int i, int j, string S, string T, vector<vector<int>>&dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if (S[i] == S[j])
        return dp[i][j]=(f(i - 1, j - 1, S, T, dp) + f(i - 1, j, S, T, dp));
    return dp[i][j]=f(i - 1, j, S, T, dp);
}

int subsequenceCount(string S, string T)
{
    int n = S.size();
    int m = T.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    return f(n-1, m-1, S, T, dp);
}
----TLE
*/

int main()
{

    string S = "banana", T = "ban";
    // cout << subsequenceCount(S, T);

    int n = S.size();
    int m = T.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S[i - 1] == T[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}