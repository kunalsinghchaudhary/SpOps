#include <iostream>
using namespace std;

int main(){
    int n, m, A[1000], B[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];
    cin >> m;
    for(int i=0;i<m;i++) cin >> B[i];

    int hashSet[10000];
    for(int i=0;i<10000;i++) hashSet[i] = 0;

    for(int i=0;i<n;i++) hashSet[A[i]] = 1;

    for(int i=0;i<m;i++){
        if(hashSet[B[i]] == 1) cout << B[i] << " ";
    }

    return 0;
}
