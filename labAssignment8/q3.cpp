#include <iostream>
using namespace std;

struct Node{
    int data; Node* left; Node* right;
    Node(int v):data(v),left(NULL),right(NULL){}
};

Node* insert(Node* root,int val){
    if(!root) return new Node(val);
    if(val<root->data) root->left=insert(root->left,val);
    else if(val>root->data) root->right=insert(root->right,val);
    return root;
}

Node* minNode(Node* node){
    while(node->left) node=node->left;
    return node;
}

Node* deleteNode(Node* root,int key){
    if(!root) return root;
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else{
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        Node* t=minNode(root->right);
        root->data=t->data;
        root->right=deleteNode(root->right,t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return 1+(l>r?l:r);
}

int minDepth(Node* root){
    if(!root) return 0;
    int l=minDepth(root->left);
    int r=minDepth(root->right);
    return 1+((l&&r)?(l<r?l:r):(l?r:l));
}

int main(){
    Node* root=NULL;
    int n,v; cin>>n;
    for(int i=0;i<n;i++){ cin>>v; root=insert(root,v); }
    int del; cin>>del;
    root=deleteNode(root,del);
    cout<<"Max Depth: "<<maxDepth(root)<<"\n";
    cout<<"Min Depth: "<<minDepth(root)<<"\n";
    return 0;
}
