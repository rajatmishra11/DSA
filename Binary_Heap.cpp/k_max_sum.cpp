#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxCombinations(int N, int k, vector<int> &a, vector<int> &b)
    {
        // code here
        set<pair<int, int>> s;
        vector<int> ans;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // maxh -> {sum,{x,y}};
        priority_queue<pair<int, pair<int, int>>> maxh;
        // pushing max 1
        maxh.push({a[N - 1] + b[N - 1], {N - 1, N - 1}});
        s.insert({N - 1, N - 1});
        // checking condition->
        while (k > 0)
        {
            pair<int, pair<int, int>> p = maxh.top();
            maxh.pop();
            int sum = p.first;
            int x = p.second.first;
            int y = p.second.second;

            ans.push_back(sum);

            if (s.find({x - 1, y}) == s.end())
            {
                maxh.push({a[x - 1] + b[y], {x - 1, y}});
                s.insert({x - 1, y});
            }
            if (s.find({x, y - 1}) == s.end())
            {
                maxh.push({a[x] + b[y - 1], {x, y - 1}});
                s.insert({x, y - 1});
            }

            k--;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int>v1={1,2,1,8};
    vector<int>v2={9,4,5,6};
    vector<int>ans=obj.maxCombinations(4,2,v1,v2);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}