#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int distinctSubsequences(string s)
{
    // Your code goes here->
    long n = s.size();
    vector<long> dp(n + 1, -1);
    map<char, int> mp;
    dp[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod;
        char ch = s[i - 1];
        if (mp.find(ch) != mp.end())
        {
            int j = mp[ch];
            dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
        }
        mp[ch] = i;
    }
}
int main()
{
    string str = "gfg";
    cout << distinctSubsequences(str);
    return 0;
}