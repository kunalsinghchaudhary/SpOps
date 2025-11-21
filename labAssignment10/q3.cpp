#include <iostream>
using namespace std;

int main(){
    int n, nums[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> nums[i];

    int freq[10000];
    for(int i=0;i<10000;i++) freq[i] = 0;

    for(int i=0;i<n;i++) freq[nums[i]]++;

    for(int i=0;i<10000;i++){
        if(freq[i] > 0){
            cout << i << " -> " << freq[i] << " times\n";
        }
    }

    return 0;
}
