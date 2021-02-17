#include<bits/stdc++.h>
using namespace std;
map<int, vector<int> > adj;
map<int, int> vis;

int bfs(int s, int lvl) {
	queue<int> q;
	q.push(s);
	vis[s] = 0;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		for(int i=0;i<adj[p].size();++i) {
			int x = adj[p][i];
			if(vis.find(x) == vis.end()) {
				q.push(x);
				vis[x] = vis[p]+1;
			}
		}
	}
	
	int r = 0;
	for(auto it=vis.begin();it!=vis.end();++it) {
		if(it->second <= lvl) ++r;
	}
	return r;
}
int main() {
	int a,b,n,s,lvl,cas=0;
	while(scanf("%d",&n) && n) {
		adj.clear();
		int cnt = 0;
		for(int i=0;i<n;++i) {
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		while(scanf("%d %d",&s,&lvl) && (s || lvl) ) {
			vis.clear();
			int r = bfs(s,lvl);
			printf("Case %d: %d nodes reachable, %d nodes not reachable from node %d with Level = %d.\n", ++cas,r,adj.size()-r,s,lvl);
		}
	}
	return 0;
}

/*
UVA 336

16
10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65
15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65
35 2 35 3 0 0

14
1 2 2 7 1 3 3 4 3 5 5 10 5 11
4 6 7 6 7 8 7 9 8 9 8 6 6 11
1 1 1 2 3 2 3 3 0 0

0
*/