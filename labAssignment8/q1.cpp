#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL){}
};

Node* insert(Node* root,int val){
    if(!root) return new Node(val);
    if(val<root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root=NULL;
    int n,v; cin>>n;
    for(int i=0;i<n;i++){ cin>>v; root=insert(root,v); }
    cout<<"Preorder: "; preorder(root); cout<<"\n";
    cout<<"Inorder: "; inorder(root); cout<<"\n";
    cout<<"Postorder: "; postorder(root); cout<<"\n";
    return 0;
}
