#include<bits/stdc++.h>
using namespace std;
vector< vector<pair<int,int> > > adj;
vector<int> dist, parent;

int dijkstra(int start, int end) {
	dist[start] = 0;
	priority_queue< pair<int,int> > pq;
	pq.push({0,start});
	while(!pq.empty()) {
		int c1 = -pq.top().first;
		int a = pq.top().second;
		pq.pop();
		for(int i=0;i<adj[a].size();++i) {
			int c2 = adj[a][i].first;
			int b = adj[a][i].second;
			if(c1+c2<dist[b]) {
				dist[b] = c1+c2;
				pq.push({-dist[b], b});
				parent[b] = a; // for printing path
			}
		}
	}
	return dist[end];
}
void path_print(int end) {
	vector<int> path;
	if(parent[end]==-1) return;
	for(int at=end;at!=-1;at=parent[at]) {
		path.push_back(at);
	} 
	reverse(path.begin(), path.end());
	for(int x: path) cout<<x<<" ";
	cout<<endl;
}
void path_recursive(int x) {
	if(x==-1) return;
	path_recursive(parent[x]);
	cout<<x<<" ";
}
int main() {
	int a,b,n,m,T,u,v,cost;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&n,&m);
		adj.resize(n+1);
		dist.resize(n+1, INT_MAX);
		parent.resize(n+1);
		fill(parent.begin(), parent.end(), -1);

		for(int i=0;i<m;++i) {
			scanf("%d %d %d",&u,&v,&cost);
			adj[u].push_back({cost,v});
		}
		scanf("%d %d",&a,&b);
		int res = dijkstra(a,b);
		if(res == INT_MAX) printf("NO\n");
		else printf("%d\n",res);
		path_print(b);
		if(parent[b]!=-1) path_recursive(b);
		cout<<endl;

		adj.clear();
		dist.clear();
	}
	return 0;
}

/*
3

3 2
1 2 5
2 3 7
1 3

3 3
1 2 4
1 3 7
2 3 1
1 3

3 1
1 2 4
1 3
*/