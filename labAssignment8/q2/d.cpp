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

Node* minNode(Node* node){
    while(node && node->left) node=node->left;
    return node;
}

Node* inorderSuccessor(Node* root, Node* x){
    Node* succ=NULL;
    while(root){
        if(x->data<root->data){ succ=root; root=root->left; }
        else root=root->right;
    }
    return succ;
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
    Node* succ=inorderSuccessor(root,node);
    if(succ) cout<<succ->data; else cout<<"No successor";
    return 0;
}
