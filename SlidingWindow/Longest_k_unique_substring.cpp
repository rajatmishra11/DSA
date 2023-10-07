#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{

    // sliding window concept
    int i = 0, j = 0, n = s.size();
    map<char, int> mp;
    int ans = -1;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans = max(ans, (j - i + 1));
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main()
{

    string str = "aabacbebebe";
    int len = 3;
    cout << longestKSubstr(str, len);
    return 0;
}