#include<bits/stdc++.h>
using namespace std;
//tc- O(n) && sc O(n)
class node{
    public:
        int data;
        node* left;
        node* right;
   
        node(int data){
            this->data=data;
            this-> left= NULL;
            this-> right=NULL;
        }
};

void inorder(node *root, vector<int>&in, int &size){
    if(root==NULL){
        return ;
    }
    inorder(root->left, in, size);
    size++;
    in.push_back(root->data);
    inorder(root->right,in, size);
}


int kthsmallest(node *root, int k){
    vector<int>in;
    int size=0;
    inorder(root,in, size);
    if(k>size or k<1) return -1;
    cout<<endl;  
    return in[k-1];   
}
int kthlargest(node *root, int k){
    vector<int>in;
    int size=0;
    inorder(root,in, size);
    if(k>size or k<1 ) return -1;
    return in[size-k];
}



int main()
{
    node* root= new node(8);
    root->right=new node(10);
    root->right->right=new node(23);
    root->left=new node(5);
    root->right->left= new node(9);


    cout<<"Enter the value of k"<<endl;
    int k;
    cin>>k;
    cout<<"kth smallest is";
    cout<<kthsmallest(root, k)<<endl;
    cout<<"kthlargest is";
    cout<<kthlargest(root,k)<<endl;
    return 0;
}