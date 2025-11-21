#include <iostream>
using namespace std;

struct Node{
    int data; Node* left; Node* right;
    Node(int v):data(v),left(NULL),right(NULL){}
};

Node* insert(Node* root,int val){
    if(!root) return new Node(val);
    if(val<root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}

int maxElement(Node* root){
    while(root->right) root=root->right;
    return root->data;
}

int main(){
    Node* root=NULL; int n,v; cin>>n;
    for(int i=0;i<n;i++){ cin>>v; root=insert(root,v); }
    cout<<maxElement(root);
    return 0;
}
