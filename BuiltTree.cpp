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

void levelorder(node *root){
    cout<<"BFS OF TREE IS-> "<<endl;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
         if(temp->right){
            q.push(temp->right);
        }
    }
    cout<<endl;
}
void levelorder2(node *root){
    cout<<"BFS OF TREE Level wise is-> "<<endl;
    queue<node*>q;
    q.push(root);
    //seperator is NULL push null to queue
    q.push(NULL);

    while(!q.empty()){
        node *temp=q.front();
        //cout<<temp->data<<" ";
        q.pop();
        if(temp==NULL){
            //prev level complete travese->
            cout<<endl;
            //leftout elements ke liye push NULL
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            //not null
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

vector<int> reverseLevelOrder(node *root)
{   
    queue<node*>q;
    q.push(root);
    //seperator is NULL push null to queue
    q.push(NULL);
    vector<int>ans;
    while(!q.empty()){
        node *temp=q.front();
        //cout<<temp->data<<" ";
        q.pop();
        if(temp==NULL){
            //prev level complete travese->
            cout<<endl;
            //leftout elements ke liye push NULL
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            //not null
            ans.push_back(temp->data);
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
            
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    node *root=NULL;
    root=BuiltTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelorder(root);
    //with labeliing of levels-> using seperator->
    levelorder2(root);
    //reverse level order traversal->
   vector<int>res= reverseLevelOrder(root);
   cout<<"Reverse level order traversal is \n";
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}