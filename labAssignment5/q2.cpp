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

int deleteKey(Node*& head, int key){
    int count = 0;
    while(head && head->data == key){
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* cur = head;
    while(cur && cur->next){
        if(cur->next->data == key){
            Node* t = cur->next;
            cur->next = t->next;
            delete t;
            count++;
        } else cur = cur->next;
    }
    return count;
}

void display(Node* head){
    while(head){
        cout<<head->data;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout<<".\n";
}

int main(){
    Node* head = nullptr;
    int n,v,key;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>v; insertEnd(head,v); }
    cin>>key;
    int count = deleteKey(head,key);
    cout<<"Count: "<<count<<" , Updated Linked List: ";
    if(!head) cout<<"Empty.\n";
    else display(head);
    return 0;
}
