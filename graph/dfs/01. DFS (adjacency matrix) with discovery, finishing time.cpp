#include <iostream>
#include<cstdio>
using namespace std;
#define white 1
#define gray 2
#define black 3
int adj[100][100],color[100];
int node, edge;
int tim=1,stim[100],ftim[100];

void dfsVisit(int x){
	color[x]=gray;
	stim[x]=tim;
	++tim;
	for(int i=0;i<node;++i){ //determine neighbour
		if(adj[x][i]==1){
			if(color[i]==white) dfsVisit(i);
		}
	}
	color[x]=black;
	ftim[x]=tim;
	++tim;
}
void dfs(){
	int i;
	for(i=0;i<node;++i){ //making white all the nodes
		color[i]=white;
	}
	for(i=0;i<node;++i){
		if(color[i]==white){
			dfsVisit(i);
		}
	}
}
int main(){
	int i,j,n1,n2;
	scanf("%d %d",&node,&edge);
	for(i=0;i<edge;++i){
		scanf("%d %d",&n1,&n2);
		adj[n1][n2]=1;
		adj[n2][n1]=1;
	}
	dfs();

	for(i=0;i<node;++i) {
		for(j=0;j<node;j++) printf("%d ",adj[i][j]);
		printf("\n");
	}
	for(i=0;i<node;++i){
		cout<<"node: "<<(char) ('A'+i)<<" "<<stim[i]<<" "<<ftim[i]<<endl;
	}
	return 0;
}

/*
input
7 7

0 1
2 0
2 1
1 3
3 4
1 4
5 6
*/