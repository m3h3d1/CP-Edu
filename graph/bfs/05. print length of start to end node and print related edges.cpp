#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > adj;
vector<int> vis,dist;
int *arr;

void bfs(vector< vector<int> > &adj, int n, int start, int end) {
	vis.resize(n+1), dist.resize(n+1);
	arr = new int[n+1];
	memset(arr,0,sizeof(int)*(n+1));
	queue<int> q;
	q.push(start);
	vis[start] = true;
	dist[start] = 0;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i=0;i<adj[x].size();++i) {
			int p = adj[x][i];
			if(!vis[p]) {
				q.push(p);
				vis[p] = true;
				dist[p] = dist[x] + 1;
				arr[p] = x;
			}
		}
	}
	if(!vis[end]) {
		printf("-1\n");
		return;
	}
	printf("%d\n",dist[end]);
	printf("%d ",end);
	int idx = end;
	while(arr[idx]) {
		printf("%d ",arr[idx]);
		idx = arr[idx];
	}
	printf("\n");
}
int main() {
	int a,b,n,m,start,end;
	scanf("%d %d",&n,&m);
	adj.resize(n+1);
	scanf("%d %d",&start,&end);
	for(int i=0;i<m;++i) {
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(adj,n,start,end);
	return 0;
}

/*
4 5
1 4

1 3
3 2
2 4
2 1
2 3
*/

/*
4 4
2 3

2 1
2 4
4 3
1 3
*/

/*
https://vjudge.net/problem/EOlymp-4853

The not oriented graph is given. Find the shortest path from vertex a to vertex b.

Input
The first line contains two integers n and m (1 ≤ n ≤ 50000, 1 ≤ m ≤ 100000) - the number of vertices and edges. The second line contains two integers a and b - the starting and ending point correspondingly. Next m lines describe the edges.

Output
If the path between a and b does not exist, print -1. Otherwise print in the first line the length l of the shortest path between these two vertices in number of edges, and in the second line print l + 1 numbers - the vertices of this path.
*/