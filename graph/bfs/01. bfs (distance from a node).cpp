//hacker earth
#include<iostream>
#include<queue>
using namespace std;
vector<int> adj[10];
int level[10];
bool vis[10];

void bfs(int s){
	queue<int> q;
	q.push(s);
	level[s]=0;
	vis[s]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<(int)adj[x].size();++i) if(!vis[adj[x][i]]){
			q.push(adj[x][i]);
			vis[adj[x][i]]=true;
			level[adj[x][i]]=level[x]+1; //for determinig distance
		}
	}
}
int main(){
	int a,b,node,edge;
	cin>>node>>edge;
	for(int i=0;i<edge;++i){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
	for(int i=1;i<=node;++i) {
		printf("node %d - level %d\n",i,level[i]);
	}
	return 0;
}

/*
4 5
1 2
1 3
2 3
2 4
3 4
*/