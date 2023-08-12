
#include<bits/stdc++.h>
using namespace std;
 
bool isSafe(int nx, int ny, int n, vector<vector<int>>arr, vector<vector<bool>>&vis){
    return (nx>=0 and nx<n and ny>=0 and ny<n and vis[nx][ny]==0 and arr[nx][ny]==1);
}

void solve(int x, int y, vector<vector<int>>&arr,int n,
 vector<string>&ans, vector<vector<bool>>&vis, string temp){
    //base case->
    if(x==n-1 and y==n-1){
        ans.push_back(temp);
        return;
    }

    //direection -> D L R U 
    //go down->
    if(isSafe(x+1,y,n,arr,vis)==1){
        vis[x][y]=1;
        solve(x+1,y,arr,n,ans,vis,temp+'D');
        vis[x][y]=0;
    }

    //go left
     if(isSafe(x,y-1,n,arr,vis)==1){
        vis[x][y]=1;
        solve(x,y-1,arr,n,ans,vis,temp+'L');
        vis[x][y]=0;
    }
    //go right
     if(isSafe(x,y+1,n,arr,vis)==1){
        vis[x][y]=1;
        solve(x,y+1,arr,n,ans,vis,temp+'R');
        vis[x][y]=0;
    }
    //go up
     if(isSafe(x-1,y,n,arr,vis)==1){
        vis[x][y]=1;
        solve(x-1,y,arr,n,ans,vis,temp+'U');
        vis[x][y]=0;
    }
}

vector<string>searchMaze(vector < vector < int >> arr, int n){
    vector<string>ans;
    if(arr[0][0]==0) return ans;
    vector<vector<bool>> vis(n, vector<bool>(n,0));
    string temp="";
    solve(0,0,arr,n,ans,vis,temp);
    return ans;
}

int main()
{
   int n = 4;
   vector < vector < int >> arr = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
  vector<string> res= searchMaze(arr,n);
  for(auto it: res){
    cout<<it<<endl;
  }
 
 
 
    return 0;
}