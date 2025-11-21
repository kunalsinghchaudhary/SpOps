#include <iostream>
using namespace std;

struct DNode{
    int data;
    DNode* next;
    DNode* prev;
    DNode(int v): data(v), next(nullptr), prev(nullptr){}
};

struct CNode{
    int data;
    CNode* next;
    CNode(int v): data(v), next(nullptr){}
};

void insertD(DNode*& head, int val){
    DNode* n = new DNode(val);
    if(!head){ head = n; return; }
    DNode* t = head;
    while(t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertC(CNode*& head, int val){
    CNode* n = new CNode(val);
    if(!head){ head = n; n->next = head; return; }
    CNode* t = head;
    while(t->next != head) t = t->next;
    t->next = n;
    n->next = head;
}

int sizeD(DNode* head){
    int count=0;
    while(head){ count++; head=head->next; }
    return count;
}

int sizeC(CNode* head){
    if(!head) return 0;
    int count=0;
    CNode* cur = head;
    do{ count++; cur=cur->next; }while(cur!=head);
    return count;
}

int main(){
    DNode* dhead = nullptr;
    CNode* chead = nullptr;
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>v; insertD(dhead,v); insertC(chead,v); }
    cout<<"Size of Doubly Linked List: "<<sizeD(dhead)<<"\n";
    cout<<"Size of Circular Linked List: "<<sizeC(chead)<<"\n";
    return 0;
}
