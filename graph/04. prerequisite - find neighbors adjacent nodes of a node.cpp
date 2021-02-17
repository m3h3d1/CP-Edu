#include <iostream>
#include<cstdio>
using namespace std;
int adj[100][100];

int main(){
	int i,node,edge,n1,n2;
	scanf("%d %d",&node,&edge);
	for(i=0;i<edge;++i){
		scanf("%d %d",&n1,&n2);
		adj[n1][n2]=1;
		adj[n2][n1]=1;
	}
	for(i=0;i<node;++i){
		if(adj[0][i]==1) printf("%d ",i);
	}
	return 0;
}

/*
for nodes of 0
*/

/*
5 6

0 1
2 0
2 1
1 3
3 4
1 4
*/