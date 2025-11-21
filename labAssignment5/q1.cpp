#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr){}
};

void insertBeginning(Node*& head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertEnd(Node*& head, int val){
    Node* n = new Node(val);
    if(!head){
        head = n;
        return;
    }
    Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}

void insertBeforeAfter(Node*& head, int val, int target, bool before){
    if(!head){
        cout<<"List empty\n";
        return;
    }
    if(before){
        if(head->data == target){
            insertBeginning(head, val);
            cout<<"Inserted\n";
            return;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while(cur && cur->data != target){
            prev = cur;
            cur = cur->next;
        }
        if(!cur){
            cout<<"Target not found\n";
            return;
        }
        Node* n = new Node(val);
        prev->next = n;
        n->next = cur;
        cout<<"Inserted\n";
    } else {
        Node* cur = head;
        while(cur && cur->data != target) cur = cur->next;
        if(!cur){
            cout<<"Target not found\n";
            return;
        }
        Node* n = new Node(val);
        n->next = cur->next;
        cur->next = n;
        cout<<"Inserted\n";
    }
}

void deleteBeginning(Node*& head){
    if(!head){
        cout<<"List empty\n";
        return;
    }
    Node* t = head;
    head = head->next;
    delete t;
    cout<<"Deleted\n";
}

void deleteEnd(Node*& head){
    if(!head){
        cout<<"List empty\n";
        return;
    }
    if(!head->next){
        delete head;
        head = nullptr;
        cout<<"Deleted\n";
        return;
    }
    Node* prev = nullptr;
    Node* cur = head;
    while(cur->next){
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
    delete cur;
    cout<<"Deleted\n";
}

void deleteValue(Node*& head, int target){
    if(!head){
        cout<<"List empty\n";
        return;
    }
    if(head->data == target){
        deleteBeginning(head);
        return;
    }
    Node* prev = head;
    Node* cur = head->next;
    while(cur && cur->data != target){
        prev = cur;
        cur = cur->next;
    }
    if(!cur){
        cout<<"Value not found\n";
        return;
    }
    prev->next = cur->next;
    delete cur;
    cout<<"Deleted\n";
}

void searchNode(Node* head, int target){
    int pos = 1;
    Node* cur = head;
    while(cur){
        if(cur->data == target){
            cout<<"Found at position "<<pos<<"\n";
            return;
        }
        cur = cur->next;
        pos++;
    }
    cout<<"Not found\n";
}

void display(Node* head){
    if(!head){
        cout<<"List empty\n";
        return;
    }
    Node* cur = head;
    while(cur){
        cout<<cur->data;
        if(cur->next) cout<<" -> ";
        cur = cur->next;
    }
    cout<<"\n";
}

int main(){
    Node* head = nullptr;
    int choice = 0;
    while(true){
        cout<<"\n1 Insert at beginning\n2 Insert at end\n3 Insert before/after a node\n4 Delete from beginning\n5 Delete from end\n6 Delete specific node\n7 Search node\n8 Display all nodes\n9 Exit\nEnter choice: ";
        if(!(cin>>choice)) break;
        if(choice==1){
            int v; cout<<"Enter value: "; cin>>v;
            insertBeginning(head, v);
        } else if(choice==2){
            int v; cout<<"Enter value: "; cin>>v;
            insertEnd(head, v);
        } else if(choice==3){
            int v,t; char c;
            cout<<"Enter new value: "; cin>>v;
            cout<<"Enter target value: "; cin>>t;
            cout<<"Insert before(b) or after(a)? "; cin>>c;
            if(c=='b' || c=='B') insertBeforeAfter(head, v, t, true);
            else insertBeforeAfter(head, v, t, false);
        } else if(choice==4){
            deleteBeginning(head);
        } else if(choice==5){
            deleteEnd(head);
        } else if(choice==6){
            int t; cout<<"Enter value to delete: "; cin>>t;
            deleteValue(head, t);
        } else if(choice==7){
            int t; cout<<"Enter value to search: "; cin>>t;
            searchNode(head, t);
        } else if(choice==8){
            display(head);
        } else if(choice==9){
            break;
        } else {
            cout<<"Invalid choice\n";
        }
    }
    while(head){
        Node* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
