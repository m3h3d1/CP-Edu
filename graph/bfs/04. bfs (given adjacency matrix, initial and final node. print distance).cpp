#include<iostream>
#include<queue>
using namespace std;
int adj[105][105];
int dist[105];//
int vis[105];

void bfs(int s,int n) {
	queue<int> q;
	q.push(s);
	vis[s]=true;
	dist[s]=0;//
	while(!q.empty()) {
		int x=q.front(); q.pop();
		for(int i=1;i<=n;++i) {
			if(adj[x][i] && !vis[i]) {
				q.push(i);
				vis[i]=true;
				dist[i]=dist[x]+1;//
			}
		}
	}
}
int main() {
	int n,s,f,x;
	cin>>n>>s>>f;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) {
		cin>>x;
		adj[i][j]=x;
	}
	bfs(s,n);
	cout<<dist[f]<<endl;
	return 0;
}

/*
4 4 3
0 1 1 1
1 0 1 0
1 1 0 0
1 0 0 0
*/

/*
Given an undirected graph. Find the distance from one given vertex to another.

The first line contains three natural numbers n, s and f (1 ≤ s, f ≤ n ≤ 100) - 
the number of vertices in the graph and the number of initial and final vertices, 
respectively. Next n lines is given in the adjacency matrix of the graph. 
If the value of the j-th element of the i-th row is 1, then the graph has a 
directed edge from vertex i to vertex j.
*/

/*
#include<bits/stdc++.h>
using namespace std;
int **adj;
vector<int> vis,dist;

void bfs(int n,int s,int f) {
    vis.resize(n+1),dist.resize(n+1);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i=1;i<=n;++i) {
            if(adj[x][i] && !vis[i]) {
                q.push(i);
                vis[i] = true;
                dist[i] = dist[x] + 1;
            }
        }
    }
    if(!vis[f]) printf("%d\n",0);
    else printf("%d\n",dist[f]);
}
int main() {
    int a,b,n,s,f;
    scanf("%d %d %d",&n,&s,&f);
    adj = new int*[n+1];
    for(int i=0;i<=n;++i) adj[i] = new int[n+1];
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            scanf("%d",&adj[i][j]);
        }
    }
    bfs(n,s,f);
    return 0;
}
*/