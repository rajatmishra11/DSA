    
    #include<bits/stdc++.h>
    using namespace std;
     

    bool dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>&vis,string word, int &k ){
        vis[row][col]=1;
        int m=board.size();
        int n=board[0].size();
      //cout<<"row, col "<<row<<","<<col<<" k:"<<k<<", word size"<<word.size()<<endl;
        if(word.size()-1==k){
           //cout<<"im returning true"<<endl;
            return true;
        }
        k=k+1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0; i<4; i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                !vis[nrow][ncol] && board[nrow][ncol]==word[k]){
                    if(dfs(nrow, ncol, board, vis, word, k)==true) return true;
                }
            
        }
        vis[row][col]=0;
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n,false));
        
        bool f=false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j]==word[0]){
                    int k=0;
                   // cout<<"before call "<<i<<j<<endl;
                    if( dfs(i,j,board, vis,word,k)){
                        //cout<<"main returning "<<endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }

int main()
    {
    
     vector<vector<char>>board= {{'a','g','b','c'},{'q','e','e','l'},{'g','b','k','s'}};
     string word="geeks";

     cout<<isWordExist(board, word);
        return 0;
    }
    
    
    