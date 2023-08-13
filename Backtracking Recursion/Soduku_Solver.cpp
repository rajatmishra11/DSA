#include<bits/stdc++.h>
using namespace std;
 

bool isSafe(int row, int col, vector<vector<char>>board, char val ){
    //same row and col par iteration hogi ->n
    int n=board.size();

    //same row
    for(int i=0; i<n; i++)
    {
        if(board[row][i]==val){
            return false;
        }
    //same col
        if(board[i][col]==val){
            return false;
        }
    //3*3 sqaure par check karo->
        int nr=3*(row/3)+i/3;
        int nc=3*(col/3)+i%3;
        if(board[nr][nc]==val){
            return false;
        }
    }
    return true;
}

bool solveSudoku( vector<vector<char>>&board){
    int n=board.size();
    for(int row=0;  row<n; row++){
        for(int col=0; col<n; col++){
            //if cell is empty
            if(board[row][col]=='.'){
                //trying values 1-9
                for(char val='1'; val<='9'; val++){
                    //check 
                    if(isSafe(row, col, board, val))
                    {
                        board[row][col]=val;
                        bool nextcall= solveSudoku(board);
                        if(nextcall == true){
                            return true;
                        }
                        else{
                            board[row][col]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


 int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solveSudoku(board);
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}
 