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


vector<int> nodesAtOddLevels(Node *root)
    {
        vector<int>ans;
        //level order traversal 
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        bool odd=true;
        
        
        while(!q.empty()){
           Node *temp=q.front();
           q.pop();

           if(temp==NULL){
            
               if(!q.empty()){
                   q.push(NULL);
               }
               odd=!odd;
               
           }

           else{
               if(odd) ans.push_back(temp->data);

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
    vector<int>ans=nodesAtOddLevels(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}