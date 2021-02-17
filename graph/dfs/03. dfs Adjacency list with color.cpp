#include <iostream>
#include <vector>
#include <stdio.h>
#define white 0
#define gray 1
#define black 2
using namespace std;

void dfs(int u,vector<int> adj[],vector<int> &color){
    color[u]=gray;
    cout<<u<<" ";
    for(int i=0;i<(int)adj[u].size();i++) if(color[adj[u][i]]==white)
        dfs(adj[u][i],adj,color);
    color[u]=black;
}
void init(vector<int> adj[],int node){
    vector<int> color(node,white);
    for(int u=0;u<node;u++) if(color[u]==white) 
        dfs(u,adj,color);
}
int main(){
    int node,edge;
    scanf("%d %d",&node,&edge);
    vector<int> adj[node]; //number of nodes is 5
    int n1,n2;
    for(int i=0;i<edge;++i){
        scanf("%d %d",&n1,&n2);
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    //neighbour of node 1
    for(int i=0;i<(int)adj[1].size();++i){
        printf("%d ",adj[1][i]);
    }
    printf("\n");
    init(adj,node);
    return 0;
}
 
/*
input
5 6

0 1
2 0
2 1
1 3
3 4
1 4
*/