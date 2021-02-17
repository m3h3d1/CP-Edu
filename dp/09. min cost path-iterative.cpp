//geeks4geeks
#include<stdio.h>
#include<algorithm>
using namespace std;
#define R 3
#define C 3

int min(int x, int y, int z){
	return min(min(x,y),z);
}
/* Returns cost of minimum cost path 
from (0,0) to (m, n) in mat[R][C]*/
int minCost(int cost[R][C], int m, int n){
	int tc[R][C]; //total cost array
	tc[0][0]=cost[0][0];
	//init 1st column
	for(int i=1;i<=m;++i){
		tc[i][0]=tc[i-1][0]+cost[i][0];
	}
	//init 1st row
	for(int j=1;j<=n;++j){
		tc[0][j]=tc[0][j-1]+cost[0][j];
	}
	//construct rest of the tc array
	for(int i=1;i<=m;++i) for(int j=1;j<=n;++j){
		tc[i][j]=min(tc[i-1][j-1],tc[i-1][j], tc[i][j-1]) 
				+cost[i][j];
	}
	return tc[m][n];		
}

int main()
{
	int cost[R][C];
	for(int i=0;i<R;++i) for(int j=0;j<C;++j) {
		scanf("%d",&cost[i][j]);
	}
	int res=minCost(cost, 2, 2);
	printf(" %d\n",res);
	return 0;
}

/*
1 2 3
4 8 2
1 5 3

here min cost path is 1-2-2-3 = 8
*/