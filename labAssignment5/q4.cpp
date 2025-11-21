#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr){}
};

void insertEnd(Node*& head, int val){
    Node* n = new Node(val);
    if(!head){ head = n; return; }
    Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}

void reverseList(Node*& head){
    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void display(Node* head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

int main(){
    Node* head = nullptr;
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>v; insertEnd(head,v); }
    reverseList(head);
    display(head);
    return 0;
}
