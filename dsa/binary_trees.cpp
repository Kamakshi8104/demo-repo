#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Node{
    
    public:
     Node* right;
     Node* left;
     int data;
     

     Node(int d){
        // root=(node*)malloc(sizeof(node));
        // root->data=c;
        right=NULL;
        left=NULL;
        data=d;


    }
     
}; 
class Bst
{
 public:
  Node* root;
 
  Bst(int d){
    
    root=new Node (d);
    
  }

  

};
void insert(Node* root,int d){
    
    Node* n=new Node(d);
    if(d<root->data){
        if(root->left==NULL){
            root->left=n;
            return;
        }
        else{
            insert(root->left,d);
            return;
        }
    }
    if(d>root->data){
        if(root->right==NULL){
            root->right=n;
            return;
        }
        else{
            insert(root->right,d);
            return;
        }
    }
    
}
void inorder(Node* root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void postorder(Node* root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  inorder(root->right);
  cout<<root->data<<" ";
  
}
vector<int> preorder_stack(Node* root){
    vector<int> v;
    stack<Node*> s;
    s.push(root);
    while(s.empty()!=true){
        Node* curr=s.top();
        s.pop();
        v.push_back(curr->data);
        if(curr->right!=NULL){
            s.push(curr->right);
        }
        if(curr->left!=NULL){
            s.push(curr->left);
        }
    }
    return v;

}
void display_preorder_stack(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
bool check_if_bst(Node* root){
   int data=root->data;
   if(root->left!=NULL){
    if(root->left->data>data){
        return false;
    }
    else{
        bool smallans=check_if_bst(root->left);
        if(smallans==false){
            return false;
        }
    }
   }
   if(root->right!=NULL){
    if(root->right->data<data){
        return false;
    }
    else{
        bool smallans=check_if_bst(root->right);
        if(smallans==false){
            return false;
        }
    }
   }
   return true;
}







    



int main() {
    // Write C++ code here
    Bst tree(5);
    insert(tree.root,10);
    insert(tree.root,15);
    insert(tree.root,1);
    insert(tree.root,12);
    insert(tree.root,3);
    insert(tree.root,8);
    inorder(tree.root);
    cout<<endl;
    postorder(tree.root);
    cout<<endl;
    vector<int> preorder_stored=preorder_stack(tree.root);
    display_preorder_stack(preorder_stored);
    if(check_if_bst(tree.root)){
        cout<<"yes its a bst"<<endl;
    }
    

    return 0;
}

