#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr){}
};

void insertEnd(Node*& head, int val){
    Node* n = new Node(val);
    if(!head){
        head = n;
        n->next = head;
        return;
    }
    Node* t = head;
    while(t->next != head) t = t->next;
    t->next = n;
    n->next = head;
}

void display(Node* head){
    if(!head) return;
    Node* cur = head;
    do{
        cout<<cur->data<<" ";
        cur = cur->next;
    } while(cur != head);
    cout<<head->data<<".\n";
}

int main(){
    Node* head = nullptr;
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        insertEnd(head,v);
    }
    display(head);
    return 0;
}
