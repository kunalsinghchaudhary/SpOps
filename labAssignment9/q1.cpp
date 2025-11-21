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
void bfs(int src){
    int q[MAXV],f=0,b=0;
    int vis[MAXV];
    for(int i=0;i<n;i++) vis[i]=0;
    q[b++]=src; vis[src]=1;
    while(f<b){
        int u=q[f++];
        cout<<u<<" ";
        for(int v=0;v<n;v++){
            if(adj[u][v] && !vis[v]){
                vis[v]=1;
                q[b++]=v;
            }
        }
    }
    cout<<"\n";
}
int main(){
    read();
    int src; cin>>src;
    bfs(src);
    return 0;
}
