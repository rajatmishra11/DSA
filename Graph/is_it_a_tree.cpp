
   #include<bits/stdc++.h>
   using namespace std;
    

void dfs(int n, int src, vector<int>&vis, vector<int>adjl[]){
        if(vis[src]==1) return;
        vis[src]=1;
        for(auto it: adjl[src]){
            dfs(n, it, vis, adjl);
        }
  }
  
    int isTree(int n, int m, vector<vector<int>> &adj) {        
        vector<int>adjl[n];
        for(auto i: adj)
        {
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
        
        vector<int>vis(n, 0);
        dfs(n,0, vis, adjl);
        
        int idx=-1;
        //unvisited check
        for(int i=0; i<vis.size() ; i++){
            if(vis[i]==0){
                idx=i;
                break;
            }
        }
        
       // if a graph of n nodes is a tree, then the graph should have n-1 edges
        if(idx==-1 && m==n-1) return 1;
        else return 0;
    }
   int main()
   {
   
     int N = 4, M = 3;
     vector<vector<int>>adj = {{0, 1}, {1, 2}, {1, 3}};
     if(isTree(N,M,adj)) cout<<"IT IS  A TREE";
     else cout<<"NOT a Tree";
    
       return 0;
   }