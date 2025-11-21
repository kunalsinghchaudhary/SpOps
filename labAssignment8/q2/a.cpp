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
    else if(val>root->data) root->right=insert(root->right,val);
    return root;
}

bool searchRec(Node* root,int key){
    if(!root) return false;
    if(root->data==key) return true;
    if(key<root->data) return searchRec(root->left,key);
    else return searchRec(root->right,key);
}

bool searchNonRec(Node* root,int key){
    while(root){
        if(root->data==key) return true;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    return false;
}

int main(){
    Node* root=NULL; int n,v,key;
    cin>>n; for(int i=0;i<n;i++){ cin>>v; root=insert(root,v); }
    cin>>key;
    cout<<"Recursive: "<<(searchRec(root,key)?"Found":"Not Found")<<"\n";
    cout<<"Non-Recursive: "<<(searchNonRec(root,key)?"Found":"Not Found");
    return 0;
}
