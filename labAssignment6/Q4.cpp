#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node* prev;
    Node(char c): data(c), next(nullptr), prev(nullptr){}
};

void insertEnd(Node*& head, char c){
    Node* n = new Node(c);
    if(!head){ head = n; return; }
    Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* tail = head;
    while(tail->next) tail = tail->next;
    while(head && tail && head != tail && tail->next != head){
        if(head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    Node* head = nullptr;
    string s;
    cin>>s;
    for(char c: s) insertEnd(head, c);
    if(isPalindrome(head)) cout<<"Palindrome";
    else cout<<"Not Palindrome";
    return 0;
}
