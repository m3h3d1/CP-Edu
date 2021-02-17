#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > adj;
int color[205];

int bipartite(int s) {
	queue<int> q;
	q.push(s);
	color[s] = 0;
	while(!q.empty()) {
		int p = q.front(); q.pop();
		for(int v: adj[p]) {
			if(color[v] == -1) {
				color[v] = color[p] ^ 1;
				q.push(v);
			}
			else if(color[v] == color[p]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int a, b, n, e;
	while(scanf("%d",&n) && n) {
		adj.resize(n);
		memset(color, -1, sizeof(color));

		scanf("%d",&e);
		for(int i=0;i<e;++i) {
			scanf("%d %d",&a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
				
		if(bipartite(0)) {
			printf("BICOLORABLE.\n");
		}
		else printf("NOT BICOLORABLE.\n");
		adj.clear();
	}
	return 0;
}

/*
3
3
0 1
1 2
2 0

3
2
0 1
1 2

9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8

0
*/

/*
uva 10004 - Bicoloring

• no node will have an edge to itself.
• the graph is nondirected. That is, if a node a is said to be connected to a node b, then you must
assume that b is connected to a.
• the graph will be strongly connected. That is, there will be at least one path from any node to
any other node.
*/