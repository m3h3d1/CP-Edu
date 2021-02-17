//http://codeforces.com/contest/29/problem/C
#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, vector<int> > adj;
map<int,bool> visited;

void dfsVisit(int x){
	visited[x]=true;
	cout<<x<<" ";
	for(int i=0;i<(int)adj[x].size();i++) if(visited[adj[x][i]]==false){
		dfsVisit(adj[x][i]);
	}
}

int main(){
	int n,i,x,y;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	map<int,vector<int> >::iterator it;
	for(it=adj.begin();it!=adj.end();++it){
		if(it->second.size()==1) break;
	}
	dfsVisit(it->first);
	cout<<endl;
	return 0;
}

/*
3
458744979 589655889
248228386 824699605
458744979 824699605
*/