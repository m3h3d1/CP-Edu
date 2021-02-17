#include "bits/stdc++.h"
using namespace std;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int N = 1e5+9;
const int inf = 1e9+7;
int st[N*4], lazy[N*4];

inline void change(int v, int l, int r, int val) {
	int nodes = (r-l+1); // tmp
	st[v] += val;
	lazy[v] += val;
}
void push(int v, int l, int r) {
	int m = (l+r)/2;
	change(lchild,lazy[v]);
	change(rchild,lazy[v]);
	lazy[v] = 0;
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

int sz[N], in[N], out[N], head[N], par[N];
vector<int> adj[N];
void dfs(int u, int p) {
	sz[u] = 1;
	par[u] = p;
	for(auto &v: adj[u]) {
		if(v==p) continue;
		dfs(v, u);
		sz[u] += sz[v];;
		if(sz[v] > sz[adj[u][0]])
			swap(v, adj[u][0]); // big child in idx 0
	}
}
int t;
void decompose(int u, int p) {
	in[u] = ++t;
	for(auto v: adj[u]) {
		if(v==p) continue;
		head[v] = (v==adj[u][0] ? head[u]:v);
		decompose(v, u);
	}
	out[u] = t;
}
inline bool isParent(int p, int u) {
	return in[p]<=in[u] && out[u]<=out[p];
}
int pathQuery(int u, int v, int n) {
	int ret = -inf;
	while(!isParent(head[u],v)) {
		ret = max(ret, query(1,1,n,in[head[u]],in[u]));
		u = par[head[u]];
	}
	swap(u,v);
	while(!isParent(head[u],v)) {
		ret = max(ret, query(1,1,n,in[head[u]],in[u]));
		u = par[head[u]];
	}
	if(in[u]>in[v]) swap(u,v);
	return max(ret, query(1,1,n,in[u],in[v]));
}

int main(){
	int a,b,n,q,T,cas=0;
	char str[10];
	scanf("%d",&n);
	for(int i=1;i<n;++i) {
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1,1); ////Will compute the subtree size of each node, their depths and immediate ancestors;
	head[1] = 1;
	decompose(1,1); //Decompose the tree into log(N) number of linear chains
	scanf("%d",&q);
	while(q--) {
		scanf("%s %d %d",str,&a,&b);
		if(str[0]=='a') update(1,1,n,in[a],out[a],b); // add b in subtree of a
		else printf("%d\n",pathQuery(a, b, n));
	}
	return 0;
}