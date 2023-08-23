
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:

  
  bool solve(int row,int col, int ind,string word,vector<vector<char>>grid,int &prev){
    if(ind==word.length()) return true;
    int n=grid.size();
    int m=grid[0].size();
    int dx[8]={-1,1,0,0,-1,-1,1,1};
    int dy[8]={0,0,-1,1,1,-1,1,-1};
    for(int i=0; i<8;i++){
        int nrow=dx[i]+row;
        int ncol=dy[i]+col;
        int dr=i;
        if(ind==1) prev=dr;
        if(dr==prev ){
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && word[ind]==grid[nrow][ncol]){
                if(solve(nrow,ncol,ind+1,word,grid,dr)) return true;
            }
        }
    }
    return false;
}

vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==word[0]){
	                int dr=0;
	                if(solve(i,j,1,word,grid,dr)) ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	}
};

int main()
{

Solution obj;

  vector<vector<char>> matrix;

    // Input data
    string input[] = {"cadbcccabec", "deaddadeaea", "ceeeaddadaa", "ddeeecbcbeb", "caedaddcbcc",
                      "dddceddeadb", "becbbdebeaa", "edceedddebb", "acceeaabaab", "cbbcbacecab"};

    // Iterate over each line of the input and add it to the matrix
    for (int i = 0; i < 10; i++) {
        vector<char> line;
        for (int j = 0; j < 10; j++) {
            line.push_back(input[i][j]);
        }
        matrix.push_back(line);
    }

    string word="dee";

 vector<vector<int>>ans= obj.searchWord(matrix,word);
 if(ans.size()==0){
    cout<<"-1";
 }
 else{
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
 }
 
    return 0;
}