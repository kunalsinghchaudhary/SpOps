#include <iostream>
using namespace std;
const int MAXV=100;
const int MAXE=1000;
int n,m;
struct Edge{ int u; int v; int w; } edges[MAXE];
void read(){
    cin>>n>>m;
    for(int i=0;i<m;i++){ cin>>edges[i].u>>edges[i].v>>edges[i].w; }
}
void sortEdges(){
    for(int i=0;i<m-1;i++){
        int mi=i;
        for(int j=i+1;j<m;j++) if(edges[j].w < edges[mi].w) mi=j;
        if(mi!=i){ Edge t=edges[i]; edges[i]=edges[mi]; edges[mi]=t; }
    }
}
int parent[MAXV];
int rankv[MAXV];
int findp(int x){
    if(parent[x]==x) return x;
    parent[x]=findp(parent[x]);
    return parent[x];
}
void unite(int a,int b){
    a=findp(a); b=findp(b);
    if(a==b) return;
    if(rankv[a]<rankv[b]) parent[a]=b;
    else if(rankv[b]<rankv[a]) parent[b]=a;
    else{ parent[b]=a; rankv[a]++; }
}
void kruskal(){
    for(int i=0;i<n;i++){ parent[i]=i; rankv[i]=0; }
    sortEdges();
    int cnt=0;
    int total=0;
    for(int i=0;i<m && cnt<n-1;i++){
        int u=edges[i].u, v=edges[i].v, w=edges[i].w;
        if(findp(u)!=findp(v)){
            unite(u,v);
            cout<<u<<" - "<<v<<" : "<<w<<"\n";
            total += w;
            cnt++;
        }
    }
    cout<<"Total weight: "<<total<<"\n";
}
int main(){
    read();
    kruskal();
    return 0;
}
