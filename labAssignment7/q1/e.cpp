#include <iostream>
using namespace std;

int partition(int a[], int l, int r){
    int pivot=a[r], i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    int t=a[i+1]; a[i+1]=a[r]; a[r]=t;
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int pi=partition(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

int main(){
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
