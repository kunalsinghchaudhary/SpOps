#include <iostream>
using namespace std;
struct Node{ int val; Node* next; Node(int v):val(v),next(0){} };
const int MOD2 = 20011;
unsigned long long keys2[MOD2];
bool used2[MOD2];
int hashPos2(unsigned long long k){ return (int)(k % MOD2); }
void setInit2(){ for(int i=0;i<MOD2;i++) used2[i]=false; }
bool setInsert2(unsigned long long k){
    int pos = hashPos2(k);
    while(used2[pos] && keys2[pos] != k) pos = (pos+1)%MOD2;
    if(!used2[pos]){ used2[pos]=true; keys2[pos]=k; return true; }
    else return false;
}
int main(){
    int n; if(!(cin>>n)) return 0;
    Node* nodes[10000];
    for(int i=0;i<n;i++){ int v; cin>>v; nodes[i]=new Node(v); if(i>0) nodes[i-1]->next = nodes[i]; }
    int pos; cin>>pos;
    if(n>0 && pos>=0 && pos<n) nodes[n-1]->next = nodes[pos];
    Node* head = n>0? nodes[0]: 0;
    setInit2();
    Node* cur = head;
    while(cur){
        unsigned long long key = (unsigned long long)(uintptr_t)cur;
        int p = hashPos2(key);
        while(used2[p] && keys2[p] != key) p = (p+1)%MOD2;
        if(used2[p]){ cout<<"true"; return 0; }
        used2[p]=true; keys2[p]=key;
        cur = cur->next;
    }
    cout<<"false";
    return 0;
}
