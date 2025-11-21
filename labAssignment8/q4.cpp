#include <iostream>
using namespace std;

struct Node{
    int data; Node* left; Node* right;
    Node(int v):data(v),left(NULL),right(NULL){}
};

Node* newNode(int v){ return new Node(v); }

bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
    if(!root) return true;
    if(min && root->data<=min->data) return false;
    if(max && root->data>=max->data) return false;
    return isBST(root->left,min,root)&&isBST(root->right,root,max);
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    cout<<(isBST(root)?"BST":"Not BST");
    return 0;
}
