//hackerearth
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> adj[10];
bool visited[10];

void dfs(int x){
	visited[x]=true;
	for(int i=0;i<(int)adj[x].size();++i) if(!visited[adj[x][i]]){
		dfs(adj[x][i]);
	}
}
int main(){
	int node,edge,x,y,cnt=0;
	cin>>node>>edge;
	for(int i=0;i<edge;++i){
		cin>>x>>y;
		//undirected graph
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=node;++i){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	cout<<"Number of connected components: "<<cnt<<endl;
	return 0;
}

/*
6
4
1 2
2 3
1 3
4 5
*/