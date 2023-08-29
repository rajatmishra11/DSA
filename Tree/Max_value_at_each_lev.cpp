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


    vector<int> maximumValue(node* root) {
        vector<int>ans;
        queue<node* >q;
        q.push(root);
        q.push(NULL);
        int ele=INT_MIN;
        
        while(!q.empty()){
            node *temp= q.front();
            q.pop();
            if(temp==NULL){
                //level completed 
                ans.push_back(ele);
                ele=INT_MIN;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                
                ele=max(ele, temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
        }
        return ans;
    }

int main()
{
    //declaring object of class node
    node *root;  
    //
    root=BuiltTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
   vector<int>ans= maximumValue(root);
   for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
   }
    return 0;
}