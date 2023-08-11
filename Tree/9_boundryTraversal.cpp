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

void traverseleft(Node *root, vector<int>&ans){
    if(!root){
        return;
    }
    //leaf node
    if(!root->left && !root->right) return;
    ans.push_back(root->data);
    if(root->left) traverseleft(root->left, ans);
    else traverseleft(root->right, ans);

}

void traverseleaf(Node *root, vector<int>&ans){
    if(!root) return;
      if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
      }
      traverseleaf(root->left, ans);
      traverseleaf(root->right, ans);

}

void traverseright(Node *root, vector<int>&ans){
    if(!root){
        return;
    }
    if(!root->left && !root->right) return;
    if(root->right){
        traverseright(root->right,ans);
    }
    else{
        traverseright(root->left,ans);
    }
    ans.push_back(root->data);

}

 vector <int> boundary(Node *root)
    {
       vector<int>ans;
       if(!root){
        return ans;
       }
       ans.push_back(root->data);

       traverseleft(root->left, ans);

       //tarverse leaf
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);

        //traverse right wala part
        traverseright(root->right, ans);
        return ans;
    }

int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    vector<int> rs=boundary(root);
    for(int i=0; i<rs.size(); i++){
        cout<<rs[i]<<" ";
    }

    return 0;
}