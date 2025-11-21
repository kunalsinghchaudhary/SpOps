#include <iostream>
using namespace std;

int main() {
    int n, nums[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> nums[i];

    int hashSet[10000];
    for(int i=0;i<10000;i++) hashSet[i] = 0;

    for(int i=0;i<n;i++){
        int x = nums[i];
        if(hashSet[x] == 1){
            cout << "true";
            return 0;
        }
        hashSet[x] = 1;
    }

    cout << "false";
    return 0;
}
