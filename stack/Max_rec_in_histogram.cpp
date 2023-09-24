#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // find left min. & right min.
        int left = 0;
        int right = 0;

        for (int j = i; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                left++;
            }
            else
            {
                break;
            }
        }

        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] >= arr[i])
            {
                right++;
            }
            else
            {
                break;
            }
        }
        int area = arr[i] * (right + left - 1);
        ans = max(ans, area);
        // cout<<arr[i]<<" ,left="<<left<<" ,right="<<right<<", ans="<<ans<<endl;
    }
    return ans;
}

int main()
{
    vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
    cout << brute_force(arr);
    return 0;
}