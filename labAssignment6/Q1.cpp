#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int v): data(v), next(nullptr), prev(nullptr){}
};

void insertFirst(Node*& head, int val){
    Node* n = new Node(val);
    if(!head){
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    Node* tail = head->prev;
    n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
    head = n;
}

void insertLast(Node*& head, int val){
    Node* n = new Node(val);
    if(!head){
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    Node* tail = head->prev;
    n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
}

void insertAfter(Node* head, int target, int val){
    if(!head){ cout<<"List empty\n"; return; }
    Node* cur = head;
    do{
        if(cur->data == target){
            Node* n = new Node(val);
            n->next = cur->next;
            n->prev = cur;
            cur->next->prev = n;
            cur->next = n;
            cout<<"Inserted\n";
            return;
        }
        cur = cur->next;
    } while(cur != head);
    cout<<"Target not found\n";
}

void insertBefore(Node*& head, int target, int val){
    if(!head){ cout<<"List empty\n"; return; }
    Node* cur = head;
    do{
        if(cur->data == target){
            Node* n = new Node(val);
            n->next = cur;
            n->prev = cur->prev;
            cur->prev->next = n;
            cur->prev = n;
            if(cur == head) head = n;
            cout<<"Inserted\n";
            return;
        }
        cur = cur->next;
    } while(cur != head);
    cout<<"Target not found\n";
}

void deleteNode(Node*& head, int key){
    if(!head){ cout<<"List empty\n"; return; }
    Node* cur = head;
    do{
        if(cur->data == key){
            if(cur->next == cur && cur->prev == cur){
                delete cur;
                head = nullptr;
                cout<<"Deleted\n";
                return;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            if(cur == head) head = cur->next;
            delete cur;
            cout<<"Deleted\n";
            return;
        }
        cur = cur->next;
    } while(cur != head);
    cout<<"Value not found\n";
}

void searchNode(Node* head, int key){
    if(!head){ cout<<"List empty\n"; return; }
    int pos = 1;
    Node* cur = head;
    do{
        if(cur->data == key){
            cout<<"Found at position "<<pos<<"\n";
            return;
        }
        cur = cur->next;
        pos++;
    } while(cur != head);
    cout<<"Not found\n";
}

void display(Node* head){
    if(!head){ cout<<"List empty\n"; return; }
    Node* cur = head;
    do{
        cout<<cur->data;
        if(cur->next != head) cout<<" <-> ";
        cur = cur->next;
    } while(cur != head);
    cout<<"\n";
}

int main(){
    Node* head = nullptr;
    int ch, val, target;
    while(true){
        cout<<"\n1 Insert at beginning\n2 Insert at end\n3 Insert before node\n4 Insert after node\n5 Delete node\n6 Search node\n7 Display\n8 Exit\nEnter choice: ";
        cin>>ch;
        if(ch==1){
            cout<<"Enter value: "; cin>>val;
            insertFirst(head,val);
        } else if(ch==2){
            cout<<"Enter value: "; cin>>val;
            insertLast(head,val);
        } else if(ch==3){
            cout<<"Enter target: "; cin>>target;
            cout<<"Enter new value: "; cin>>val;
            insertBefore(head,target,val);
        } else if(ch==4){
            cout<<"Enter target: "; cin>>target;
            cout<<"Enter new value: "; cin>>val;
            insertAfter(head,target,val);
        } else if(ch==5){
            cout<<"Enter value to delete: "; cin>>val;
            deleteNode(head,val);
        } else if(ch==6){
            cout<<"Enter value to search: "; cin>>val;
            searchNode(head,val);
        } else if(ch==7){
            display(head);
        } else if(ch==8){
            break;
        } else cout<<"Invalid\n";
    }
    return 0;
}
