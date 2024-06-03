#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[i] = 1;

    for (int it = 0; it < adj[i].size(); it++)
    {
        if (!vis[it] && adj[i][it])
        {
            dfs(it, vis, adj);
        }
    }
}

vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
{
    // code here

    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1 && i != j)
            {
                adj[i][j] = 1;
            }
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> vis(n, 0);

        dfs(i, vis, adj);

        ans.push_back(vis);
    }
    return ans;
}

int main()
{

    vector<vector<int>> graph = {{1, 1, 0, 1},
                                 {0, 1, 1, 0},
                                 {0, 0, 1, 1},
                                 {0, 0, 0, 1}};
    int n = graph.size();
    vector<vector<int>> ans = transitiveClosure(n, graph);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}