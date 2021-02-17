#include<iostream>
#include<vector>
#include<deque>
#include<limits.h>
using namespace std;
#define mxn 9
struct node {
	int to,weight;
};
vector<node> edges[mxn];
int dist[mxn];

void bfs01(int s){
	for(int i=0;i<mxn;++i) {
		dist[i]=INT_MAX;
	}
	deque<int> q; //double ende queue
	dist[s]=0;
	q.push_back(s);
	while(!q.empty()) {
		int x=q.front();
		q.pop_front();
		for(int i=0;i<(int)edges[x].size();++i){
			//checking for optimal distance
			if(dist[edges[x][i].to] > dist[x]+edges[x][i].weight){
				dist[edges[x][i].to] = dist[x]+edges[x][i].weight;
				// Put 0 weight edges to front and
                // 1 weight  edges to back so that  
                // vertices are processed in increasing order of weights.
                if(edges[x][i].weight==0)
                	q.push_front(edges[x][i].to);
                else
                	q.push_back(edges[x][i].to);
			}
		}
	}
}
int main(){
	int a,b,w,node,edge;
	cin>>node>>edge;
	for(int i=0;i<edge;++i){
		cin>>a>>b>>w;
		edges[a].push_back({b,w});
		edges[b].push_back({a,w});
	}
	bfs01(0);
	for(int i=0;i<=node;++i){
		cout<<dist[i]<<" ";
	}
	return 0;
}
/*
8 13
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1
*/