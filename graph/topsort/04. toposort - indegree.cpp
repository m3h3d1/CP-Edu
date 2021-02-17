#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > adj;
int *indegree;

void toposort(int n) {
	priority_queue<int> q; //to sort the order, use queue if sorted is not needed
	vector<int> v;
	for(int i=1;i<=n;++i) if(!indegree[i]) q.push(i*-1);
	while(!q.empty()) {
		int x = q.top() * -1; q.pop();
		v.push_back(x);
		for(int i=0;i<adj[x].size();++i) {
			int p = adj[x][i];
			if(--indegree[p] == 0) q.push(p*-1);
		}
	}
	if(v.size()<n) printf("toposort doesn't exist");
	else for(int i=0;i<v.size();++i) printf("%d ",v[i]);
	printf("\n");
}
int main() {
	int a,b,n,m;
	scanf("%d %d",&n,&m);
	adj.resize(n+1);
	indegree = new int[n+1];
	memset(indegree,0,sizeof(int)*(n+1));
	for(int i=0;i<m;++i) {
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	toposort(n);
	return 0;
}

/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6
*/

/*
2 2
1 2
2 1
*/