#include <iostream>
using namespace std;

int main(){
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int start=0, end=n-1;
    while(start<end){
        int minIndex=start, maxIndex=start;
        for(int i=start;i<=end;i++){
            if(a[i]<a[minIndex]) minIndex=i;
            if(a[i]>a[maxIndex]) maxIndex=i;
        }
        int t=a[start]; a[start]=a[minIndex]; a[minIndex]=t;
        if(maxIndex==start) maxIndex=minIndex;
        t=a[end]; a[end]=a[maxIndex]; a[maxIndex]=t;
        start++; end--;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
