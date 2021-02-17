#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);
char grid[105][105];
int n,m;

void floodfill(int i,int j){
	if(i<0 || j<0 || i==n || j==m || grid[i][j]!='@') return;
	grid[i][j]='1';
	floodfill(i-1,j-1); floodfill(i-1,j); floodfill(i-1,j+1);
	floodfill(i,j-1);						floodfill(i,j+1);
	floodfill(i+1,j-1); floodfill(i+1,j); floodfill(i+1,j+1);
}
int main(){
	int i,j,cnt;
	while(scanf("%d %d",&n,&m) && n){
		getchar();
		for(i=0;i<n;i++){
			gets(grid[i]);
		}
		cnt=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(grid[i][j]=='@'){
					floodfill(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}