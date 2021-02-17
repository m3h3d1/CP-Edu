#include<iostream>
#include<vector>
using namespace std;
vector<int> *adj;
bool *visited,*recurArr;

int dfs(int x) {
	visited[x]=1;
	recurArr[x]=1;

	//recursive call to all the adjacent vertices
	for(int i=0;i<adj[x].size();++i) {
		if(!visited[adj[x][i]] && dfs(adj[x][i]))
			return 1;
		else if(recurArr[adj[x][i]])
			return 1;
	}

	//if reached here means cycle has not found in DFS from this vertex
	//reset
	recurArr[x]=0;
	return 0;
}
int iscycle(int n) {
	visited=new bool[n];
	recurArr=new bool[n];
	for(int i=0;i<n;++i) {
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
	}
	cout<<iscycle(n);
	return 0;
}
/*
@ Visited[] is used to keep track of already visited 
	vertices during the DFS is never gets
@ Recursion stack[] is used from keep track of visiting vertices 
	during DFS from particular vertex and gets reset once cycle is 
	not found from that vertex and will try DFS from other vertices.
*/

/*
4 4

0 1
1 2
2 3
3 1
*/