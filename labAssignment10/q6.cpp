#include <iostream>
using namespace std;
const int MOD3 = 20011;
int keys3[MOD3];
bool used3[MOD3];
int hashPos3(long long k){ if(k<0) k = -k; return (int)(k % MOD3); }
void setInit3(){ for(int i=0;i<MOD3;i++) used3[i]=false; }
bool setInsert3(long long k){
    int pos = hashPos3(k);
    while(used3[pos] && keys3[pos] != (int)k) pos = (pos+1)%MOD3;
    if(!used3[pos]){ used3[pos]=true; keys3[pos]=(int)k; return true; }
    else return false;
}
int main(){
    int n; if(!(cin>>n)) return 0;
    int arr[20000];
    for(int i=0;i<n;i++) cin>>arr[i];
    setInit3();
    for(int i=0;i<n;i++){
        if(arr[i]==-1) continue;
        int k = arr[i];
        int pos = hashPos3(k);
        while(used3[pos] && keys3[pos] != k) pos = (pos+1)%MOD3;
        if(used3[pos]){ cout<<"Duplicates Found"; return 0; }
        used3[pos]=true; keys3[pos]=k;
    }
    cout<<"No Duplicates";
    return 0;
}
