#include<bits/stdc++.h>
using namespace std;
struct Edge {
	int u,v,w;
};
vector<int> boss;

bool cmp(Edge a, Edge b) {
	return a.w<b.w;
}
int find(int a) {
	if(a == boss[a]) return a;
	return boss[a] = find(boss[a]);
}

int main() {
	int n,T,cas = 0;
	scanf("%d",&T);
	while(T--) {
		vector<Edge> edges;
		scanf("%d",&n);
		boss.resize(n+1);
		for(int i=0;i<=n;++i) boss[i] = i;
		Edge x;
		while(scanf("%d %d %d",&x.u,&x.v,&x.w) && (x.u || x.v || x.w)) {
			edges.push_back(x);
		}
		int s = 0;
		sort(edges.begin(),edges.end(),cmp);
		for(int i=0;i<edges.size();++i) {
			int a = find(edges[i].u);
			int b = find(edges[i].v);
			if(a != b) {
				boss[a] = b;
				s += edges[i].w;
			}
		}
		printf("Case %d: %d\n",++cas,s);
	}
	return 0;
}