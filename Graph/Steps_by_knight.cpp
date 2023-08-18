#include<bits/stdc++.h>
using namespace std;
 

   bool isValid(int i, int j, int n, vector<vector<bool>>&visited){
        if(i>=0 && i<n && j>=0 && j<n && !visited[i][j]){
            return true;
        }
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n = N;
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int x1 = KnightPos[0]-1, y1 = KnightPos[1]-1;
	    
	    if(x1 == tx && y1 == ty) return 0;
	    
	    vector<vector<bool>>visited(n, vector<bool>(n, false));
	    
	    queue<pair<int, int>>q;
	    q.push({x1, y1});
	    visited[x1][y1] = true;
	    
	    int ans = 0;
	    while(!q.empty()){
	        
	        int size = q.size();
	        ans++;
	        while(size--){
	            int xx = q.front().first;
	            int yy = q.front().second;
				q.pop();

	            
	            int ax[] = {-2,-2,2,2,-1,-1,1,1};
	            int ay[] = {-1,1,1,-1,-2,2,-2,2};
	            
	            for(int i=0; i<8; i++){
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                if(nx == tx && ny == ty) return ans;
	                
	                if(isValid(nx, ny, n, visited)){
	                    visited[nx][ny] = true;
	                    q.push({nx, ny});
	                }
	            }
	           
	        }
	    }
	    return ans;
	}

int main()
{

 
 int N,src_x,src_y,des_x,des_y;
 cin>>N>>src_x>> src_y>> des_x>> des_y;
 vector<int> KnightPos={src_x,src_y};
 vector<int> TargetPos={des_x, des_y};
 cout<< minStepToReachTarget(KnightPos,TargetPos,N);
    return 0;
}