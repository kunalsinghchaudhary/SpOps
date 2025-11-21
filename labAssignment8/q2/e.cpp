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

Node* maxNode(Node* node){
    while(node && node->right) node=node->right;
    return node;
}

Node* inorderPredecessor(Node* root, Node* x){
    Node* pred=NULL;
    while(root){
        if(x->data>root->data){ pred=root; root=root->right; }
        else root=root->left;
    }
    return pred;
}

Node* search(Node* root,int key){
    if(!root||root->data==key) return root;
    if(key<root->data) return search(root->left,key);
    else return search(root->right,key);
}

int main(){
    Node* root=NULL; int n,v,key;
    cin>>n; for(int i=0;i<n;i++){ cin>>v; root=insert(root,v); }
    cin>>key;
    Node* node=search(root,key);
    Node* pred=inorderPredecessor(root,node);
    if(pred) cout<<pred->data; else cout<<"No predecessor";
    return 0;
}
