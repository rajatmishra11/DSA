#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string s)
{
    // code
    vector<int> charcount(256, 0);

    int i = 0, j = 0, n = s.size(), ans = 0;
    while (j < n)
    {
        charcount[s[j]] += 1;
        while (charcount[s[j]] > 1)
        {
            charcount[s[i]]--;
            i += 1;
        }
        ans = max(ans, (j - i + 1));
        j++;
    }
    return ans;
}

/*
int longestUniqueSubsttr(string s)
{
    // code
    int n = s.size(), i = 0, j = 0;
    map<char, int> mp;
    int ans = 0;
    while (j < n)
    {
        mp[s[j]]++;
        int k = (j - i + 1);

        if (mp.size() == k)
        {
            ans = max(ans, k);
            // cout<<ans<<" ";
            j++;
        }
        else if (mp.size() < k)
        {
            while (mp.size() < (j - i + 1))
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
tle
*/

int main()
{
    string temp="abchdji";
    cout<<longestUniqueSubsttr(temp);
    return 0;
}