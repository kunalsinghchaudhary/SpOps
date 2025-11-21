#include <iostream>
using namespace std;
const int MAXV=100;
const int INF=1000000000;
int n,m;
int adj[MAXV][MAXV];
void read(){
    for(int i=0;i<MAXV;i++) for(int j=0;j<MAXV;j++) adj[i][j]=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u][v]=w; adj[v][u]=w;
    }
}
void prim(){
    int key[MAXV], inMST[MAXV], parent[MAXV];
    for(int i=0;i<n;i++){ key[i]=INF; inMST[i]=0; parent[i]=-1; }
    key[0]=0;
    for(int cnt=0; cnt<n-1; cnt++){
        int u=-1, mn=INF;
        for(int v=0; v<n; v++) if(!inMST[v] && key[v]<mn){ mn=key[v]; u=v; }
        if(u==-1) break;
        inMST[u]=1;
        for(int v=0; v<n; v++){
            if(adj[u][v] && !inMST[v] && adj[u][v] < key[v]){
                key[v]=adj[u][v];
                parent[v]=u;
            }
        }
    }
    int total=0;
    for(int v=1; v<n; v++){
        if(parent[v]!=-1){ cout<<parent[v]<<" - "<<v<<" : "<<adj[parent[v]][v]<<"\n"; total += adj[parent[v]][v]; }
    }
    cout<<"Total weight: "<<total<<"\n";
}
int main(){
    read();
    prim();
    return 0;
}
