#include<iostream>
#include<vector>
using namespace std;
vector<int> *adj;
bool *visited;

int dfs(int x) {
	visited[x]=1;

	//visit neighbours except it's direct parent
	for(int i=0;i<adj[x].size();++i) if(adj[x][i]!=x) { //check the adjacent vertex to the current vertex
		
		//if destination vertex is not its direct path then
			//if here means this destination vertex is already visited
			//means cycle has been detected	
		if(visited[adj[x][i]])
			return 1;

		// recursion from destination node
		else if(dfs(adj[x][i]))
			return 1;
	}
	return 0;
}
int iscycle(int n) {
	visited=new bool[n];
	for(int i=0;i<n;++i) if(!visited[i]) {
		if(dfs(i)) return 1;
	}
	return 0;
}
int main() {
	int a,b,n,m;
	cin>>n>>m;
	adj=new vector<int> [n];
	for(int i=0;i<m;++i) {
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<iscycle(n);
	return 0;
}
/*
$ Do DFS from every vertex.
$ During DFS, for any current vertex ‘x’ (currently visiting vertex) if there an adjacent vertex ‘y’ is present which is already visited and no ‘y’ is not a direct parent of ‘x’ then there is a cycle in graph.
$ Why not parent:
	Let’s assume, vertex ‘x’ and ‘y’ and we have edge between them. x--y.
	Now do DFS from ‘x’, once you reach to ‘y’, will do the DFS from ‘y’ and adjacent vertex is ‘x’ and since its already visited so there should be cycle but actually there is no cycle since ‘x’ is a parent of ‘y’. That is why we will ignore visited vertex if it is parent of current vertex.
*/

/*
6 6

0 1
1 2
2 3
3 4
4 5
5 2
*/