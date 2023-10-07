#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid)
{
    vis[row][col] = true;
    int n = grid[0].size();
    int m = grid.size();
    // all 4 directions-
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = delrow[i] + row;
        int ncol = delcol[i] + col;
        // valid->
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == false)
        {
            dfs(nrow, ncol, vis, grid);
        }
    }
    return;
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here
    // boundry se chute hue ko-> sb 1 se connect kar do-
    // fhir dekhenge ki kon sa bacha hai->
    int n = grid[0].size();
    int m = grid.size();
  //  cout<<m<<", "<<n<<endl;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    // traversee all boundries->
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {  
            //cout<<i<<", " <<j<<" : "<<endl;
            if ((i == 0 or j == 0 or i == m - 1 or j == n - 1) && vis[i][j] == 0 && grid[i][j] == 1)
            {  
                //cout<<"dfs of "<<i<<", "<<j<<endl;
                dfs(i, j, vis, grid);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == false)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{

    vector<vector<int>> grid = { {0, 0, 0, 0},
                                 {1, 0, 1, 0},
                                 {0, 1, 1, 0},
                                 {0, 0, 0, 0} };
                                 
 cout<< numberOfEnclaves(grid);
    return 0;
}