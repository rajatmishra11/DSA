#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{
    int ans = 0;
    bool flag = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int dig = str[i] - '0';
        if (dig >= 0 && dig <= 10)
        {
            ans = ans * 10 + dig;
        }
        else if (str[i] == '-' && !flag && i == 0)
        {
            flag = 1;
        }
        else
            return -1;
    }
    if (flag)
    {
        ans = -ans;
    }
    return ans;
}

int main()
{

    cout << atoi("7612571");

    return 0;
}