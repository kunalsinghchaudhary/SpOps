#include <iostream>
using namespace std;
const int MOD1 = 20011;
int keys1[MOD1];
int vals1[MOD1];
bool used1[MOD1];
int hashPos1(long long k){
    if(k<0) k = -k;
    return (int)(k % MOD1);
}
void mapInit1(){
    for(int i=0;i<MOD1;i++) used1[i]=false;
}
void mapInc1(long long k){
    int pos = hashPos1(k);
    while(used1[pos] && keys1[pos] != (int)k) pos = (pos+1)%MOD1;
    if(!used1[pos]){ used1[pos]=true; keys1[pos]=(int)k; vals1[pos]=1; }
    else vals1[pos] += 1;
}
int mapGet1(long long k){
    int pos = hashPos1(k);
    while(used1[pos]){
        if(keys1[pos]==(int)k) return vals1[pos];
        pos = (pos+1)%MOD1;
    }
    return 0;
}
int main(){
    int n;
    if(!(cin>>n)) return 0;
    int a[10000];
    for(int i=0;i<n;i++) cin>>a[i];
    mapInit1();
    for(int i=0;i<n;i++) mapInc1(a[i]);
    for(int i=0;i<n;i++){
        if(mapGet1(a[i])==1){ cout<<a[i]; return 0; }
    }
    cout<<-1;
    return 0;
}
