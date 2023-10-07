#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str)
{
    // code here
    int ans = 0;
    int arr[] = {1, 5, 10, 50, 100, 500, 1000};
    char ch[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    // IV- 4,
    //  XI- 11
    //  IL=49
    int prev_idx = -1, curr_idx = 0;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << ", ";
        int j = 0;
        while (j <= 7)
        {
            if (str[i] == ch[j])
            {
                curr_idx = j;
                if (curr_idx > prev_idx)
                {
                    // cout << curr_idx << ", " << prev_idx << ", " << ans << endl;
                    if (prev_idx != -1)
                        ans += arr[curr_idx] - 2 * arr[prev_idx];
                    else
                        ans += arr[curr_idx];
                    prev_idx = j;
                }
                else
                {
                    // cout << curr_idx << ", " << prev_idx << ", " << ans << endl;
                    ans += arr[curr_idx];
                    prev_idx = j;
                }
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << romanToDecimal(str);
    return 0;
}