#include <iostream>
using namespace std;

int heapArr[1000];
int heapSize = 0;

void heapifyDown(int i){
    while(true){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;
        if(l < heapSize && heapArr[l] > heapArr[largest]) largest = l;
        if(r < heapSize && heapArr[r] > heapArr[largest]) largest = r;
        if(largest == i) break;
        int t = heapArr[i]; heapArr[i] = heapArr[largest]; heapArr[largest] = t;
        i = largest;
    }
}

void insert(int val){
    if(heapSize >= 1000) return;
    heapArr[heapSize] = val;
    int i = heapSize;
    heapSize++;
    while(i > 0 && heapArr[(i-1)/2] < heapArr[i]){
        int t = heapArr[i]; heapArr[i] = heapArr[(i-1)/2]; heapArr[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int extractMax(){
    if(heapSize <= 0) return -1;
    int root = heapArr[0];
    heapSize--;
    if(heapSize > 0) heapArr[0] = heapArr[heapSize];
    heapifyDown(0);
    return root;
}

int getMax(){
    if(heapSize <= 0) return -1;
    return heapArr[0];
}

int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(x);
    }
    cout<<getMax()<<"\n";
    cout<<extractMax()<<"\n";
    for(int i=0;i<heapSize;i++) cout<<heapArr[i]<<" ";
    cout<<"\n";
    return 0;
}

