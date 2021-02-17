#include "bits/stdc++.h"
using namespace std;
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int N = 1e5+9;
const int inf = 1e9+7;

// Segment Tree
int st[N*4], lazy[N*4];
inline void change(int v, int l, int r, int val) {
    int nodes = (r-l+1);
    st[v] += val;
    lazy[v] += val;
}
inline void push(int v, int l, int r) {
    int m = (l+r)/2;
    change(lchild,lazy[v]);
    change(rchild,lazy[v]);
    lazy[v] = 0;
}
void update(int v, int l, int r, int i, int j, int val) {
    if(l>=i && r<=j) {
        change(v,l,r,val);
        return;
    }
    if(lazy[v]) push(v,l,r);
    int m = (l+r)/2;
    if(j<=m) update(lchild,i,j,val);
    else if(i>m) update(rchild,i,j,val);
    else {
        update(lchild,i,j,val);
        update(rchild,i,j,val);
    }
    st[v] = max(st[v*2], st[v*2+1]);
}
int query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) {
        return st[v];
    }
    if(lazy[v]) push(v,l,r);
    int m = (l+r)/2;
    if(j<=m) return query(lchild,i,j);
    else if(i>m) return query(rchild,i,j);
    else return max(query(lchild,i,m), query(rchild,m+1,j));
}
// End of Segment Tree

vector<int> adj[N];
int sz[N], parent[N], level[N], son[N];
void dfs(int u, int p) {
    sz[u] = 1;
    for(auto& v: adj[u]) if(v!=p) {
        parent[v] = u;
        level[v] = level[u]+1;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v]>sz[son[u]])
            son[u] = v;
    }
}

int newid[N], in[N], out[N], top[N], nextid;
void decompose(int u, int p) {
    in[u] = newid[u] = ++nextid;
    if(son[parent[u]]==u) top[u] = top[parent[u]];
    else top[u] = u;
    if(son[u]) decompose(son[u], u);
    for(auto& v: adj[u]) if(v!=p && v!=son[u])
        decompose(v, u);
    out[u] = nextid;
}
int pathQuery(int u, int v, int n) {
    int mx = -inf;
    while(top[u] != top[v]) {
        if(level[top[u]]<level[top[v]])
            swap(u, v);
        mx = max(mx, query(1, 1, n, newid[top[u]], newid[u]));
        u = parent[top[u]];
    }
    if(level[u]>level[v]) swap(u, v);
    mx = max(mx, query(1, 1, n, newid[u], newid[v]));
    return mx;
}

int main(){
    int a,b,n,q,T,cas=0;
    scanf("%d",&n);
    for(int i=1;i<n;++i) {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    nextid = 0;
    dfs(1, 1);
    decompose(1, 1);
    
    scanf("%d",&q);
    char str[10];
    while(q--) {
        scanf("%s %d %d",str,&a,&b);
        if(str[0]=='a') update(1,1,n,in[a],out[a],b); // add b in subtree of a
        else printf("%d\n",pathQuery(a, b, n));
    }
    return 0;
}