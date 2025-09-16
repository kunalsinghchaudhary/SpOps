#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,2,3,5,6};
    int n=arr.size();
    for(int el:arr){
        if(arr[el+1]!=arr[el]+1){
             cout<<"The missing element in sorted array is:"<<arr[el]+1<<endl;
           break; 
        }
       
    }
    return 0;
}