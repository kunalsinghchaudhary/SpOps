#include <iostream>
using namespace std;
const int MAXV=100;
int n,m;
int adj[MAXV][MAXV];
void read(){
    for(int i=0;i<MAXV;i++) for(int j=0;j<MAXV;j++) adj[i][j]=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u][v]=1; adj[v][u]=1;
    }
}
void dfsUtil(int u,int vis[]){
    vis[u]=1;
    cout<<u<<" ";
    for(int v=0;v<n;v++) if(adj[u][v] && !vis[v]) dfsUtil(v,vis);
}
void dfs(int src){
    int vis[MAXV];
    for(int i=0;i<n;i++) vis[i]=0;
    dfsUtil(src,vis);
    cout<<"\n";
}
int main(){
    read();
    int src; cin>>src;
    dfs(src);
    return 0;
}
