#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
#define white 1
#define gray 2
#define black 3
int adj[100][100],color[100];
int node,edge;
int parent[100],dis[100];

void bfs(int startingNode){
	for(int i=0;i<node;++i){
		color[i]=white;
		dis[i]=INT_MIN; //INT_MIN is -2147483648
		parent[i]=-1;
	}
	dis[startingNode]=0; //distance of starting node is 0
	parent[startingNode]=-1; //no parent node for starting node

	queue<int> q;
	q.push(startingNode);

	while(!q.empty()){
		int x=q.front();
		q.pop();
		color[x]=gray;
		printf("%d ",x);
		for(int i=0;i<node;++i){
			if(adj[x][i]==1){
				if(color[i]==white){
					//x er neighbour i
					//x no node ta hocche i no node er parent
					dis[i]=dis[x]+1;
					parent[i]=x;
					q.push(i);
				}
			}
		}
		color[x]=black;
	}
}
int main(){
	int n1,n2;
	scanf("%d %d",&node,&edge);
	for(int i=0;i<edge;++i){
		scanf("%d %d",&n1,&n2);
		adj[n1][n2]=1;
		adj[n2][n1]=1;
	}
	bfs(0); //starting node 0
	printf("\n%d",parent[5]); //parent of 5 no node
	printf("\n%d",dis[6]); //distance of 0 to 6 no node
	return 0;
}

/*
input
8 7

0 1
0 2
1 3
2 4
2 5
3 6
3 7
*/