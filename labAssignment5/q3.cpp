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

int findMiddle(Node* head){
    if(!head) return -1;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main(){
    Node* head = nullptr;
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>v; insertEnd(head,v); }
    cout<<findMiddle(head);
    return 0;
}
