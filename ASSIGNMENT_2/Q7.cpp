#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cout<<"Enter values of matrix:"<<endl;
        cin>>A[i];
    }
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
                count++;
            }
        }
    }
    cout<<"Total inversions are:"<<count<<endl;
    return 0;
}