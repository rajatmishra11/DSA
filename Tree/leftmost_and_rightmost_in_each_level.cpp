#include<bits/stdc++.h>
using namespace std;
 
class  node
{
    public:
        int data;
        node *left;
        node *right;

        //constructor
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

node *BuiltTree(node *root){
    cout<<"Enter the data of node: "<<endl;
    int data;
    cin>>data;

    //creating a new node->
    root=new node(data);

    //for NULL
    if(data==-1) {
        return NULL;
    }

    //recursive call for left
    cout<<"Enter the data for Left of "<<data<<endl;
    root->left= BuiltTree(root->left);

    //recursive call for right
    cout<<"Enter the data for Right of "<<data<<endl;
    root->right=BuiltTree(root->right);

    //in last return root;
    return root;
}

void printCorner(node *root)
{

// Your code goes here
//using level order traversal
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0; i<size; i++){
            node *temp=q.front();
            q.pop();
            if(i==0 or i==size-1) cout<<(temp->data)<<" ";
            //if left exist push to queue
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main()
{
    //declaring object of class node
    node *root;  
    //
    root=BuiltTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
   printCorner(root);
    return 0;
}