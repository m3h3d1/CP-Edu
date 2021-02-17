#include <iostream>
using namespace std;
int adj[100][100];

int main(){
	int i,j,node,edge,n1,n2;
	scanf("%d %d",&node,&edge);
	for(i=0;i<edge;++i){
		scanf("%d %d",&n1,&n2);
		adj[n1][n2]=1;
		adj[n2][n1]=1;
	}

	for(i=0;i<node;++i) {
		for(j=0;j<node;j++) printf("%d ",adj[i][j]);
		printf("\n");
	}
	return 0;
}

/*
input
5 6
0 1
2 0
2 1
1 3
3 4
1 4
*/