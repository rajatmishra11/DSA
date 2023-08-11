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

int height(Node *root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}

// /* O(n^2)
int diameter(Node *root){
    //answer lies in leftsubtree
    if(root==NULL) return 0;
    int ob1=diameter(root->left);
    //answer lies in leftsubtree
    int ob2=diameter(root->right);
    //answer lies in leftsubtree and rightsubtree
    int ob3=height(root->left) + height(root->right)+1;
    return max(ob1 , max(ob2, ob3));
}

void diameter2(Node *root, int &maxi){
    if(!root) return ;
    int lh=height(root->left);
    int rh=height(root->right);
    maxi= max(1+lh+rh,maxi);
    diameter2(root->left,maxi);
    diameter2(root->right,maxi);
    return;
}

int diameter3(Node *root, int &maxi){
    if(root==NULL){
        return 0;
    }
    int lh=diameter3(root->left, maxi);
    int rh=diameter3(root->right, maxi);
    maxi=max(maxi,1+lh+rh );
    return 1+ max(lh,rh);
}

//pair-> {diameter, height};
pair<int,int> diameter4(Node *root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int> left= diameter4(root->left);
    pair<int,int> right= diameter4(root->right);

    int op1= left.first; //left st ka diameter
    int op2= right.first;  //right st ka diameter
    //left ki height + right ki height +1
    int op3= left.second+right.second+1;

    pair<int,int>ans; //{final diameter, height}
    ans.first= max(op1,max(op2,op3)); //final diameter
    ans.second= max(left.second, right.second)+1; //height
    //returning pair->
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
    root->left->left->left->left= new Node(7);

    //                   1
    //           2                3
    //       4       5
    //    6
    // 7

    cout<<"Diameter of Tree is\nM1: "<<diameter(root);
    int maxi=0;
    diameter2(root,maxi);
    cout<<"\nM2: " <<maxi<<endl;
    maxi=0;
    diameter3(root, maxi);
    cout<<"\nM3: "<<maxi<<endl;

    cout<<"\nM4: "<<diameter4(root).first;
    return 0;
}