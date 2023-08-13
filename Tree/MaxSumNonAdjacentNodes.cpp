#include<bits/stdc++.h>
using namespace std;
 
class Node
{   
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data=data;
            left=right=NULL;
        }
};

pair<int,int>  solve(Node *root){
    if(root==NULL){
        pair<int,int>p= make_pair(0,0);
        return p;
    }

    //left se laao
    pair<int,int> left= solve(root->left);
    //right se laao
    pair<int,int> right= solve(root->right);

    pair<int,int> res;
    //maximum sum including the node
    res.first=root->data+ left.second+ right.second;
     //maximum sum Excluding the 
    res.second=max(left.first, left.second)+ max(right.first, right.second);
    return res;
}

int maxsumnonadjacentnodes(Node *root){
     pair<int,int> ans= solve(root);
     return max(ans.first, ans.second);
}

int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);

        //                 1
        //         2               3
        //     4       5
        // 6
    cout<<maxsumnonadjacentnodes(root);
    return 0;
}