/* 3rd one */
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




/* 2nd one */

// #include<stdio.h>
// #include<stdbool.h>
// #include<string.h>
// #define db(x) printf("%s is %d\n",#x,x);
// char grid[105][105];
// bool vis[105][105];
// int n,m;

// void floodfill(int i,int j){
// 	if(i<0 || j<0 || i==n || j==m || grid[i][j]!='@' || vis[i][j]==1) return;
// 	vis[i][j]=1;
// 	floodfill(i-1,j); /* up */
// 	floodfill(i+1,j); /* down */
// 	floodfill(i,j-1); /* left */
// 	floodfill(i,j+1); /* right */
// 	floodfill(i-1,j-1); /* upper-left corner */
// 	floodfill(i-1,j+1); /* upper-right corner */
// 	floodfill(i+1,j-1); /* lower-left corner */
// 	floodfill(i+1,j+1); /* lower-right corner */
// }
// int main(){
// 	int i,j,cnt;
// 	while(scanf("%d %d",&n,&m) && n){
// 		getchar();
// 		memset(vis,0,sizeof(vis));
// 		for(i=0;i<n;i++){
// 			gets(grid[i]);
// 		}
// 		cnt=0;
// 		for(i=0;i<n;i++){
// 			for(j=0;j<m;j++){
// 				if(grid[i][j]=='@' && vis[i][j]==0){
// 					floodfill(i,j);
// 					cnt++;
// 				}
// 			}
// 		}
// 		printf("%d\n",cnt);
// 	}
// 	return 0;
// }



/*1st one */

// #include<stdio.h>
// #include<stdbool.h>
// #include<string.h>
// #define db(x) printf("%s is %d\n",#x,x);
// char grid[105][105];
// bool vis[105][105];
// int n,m;

// void floodfill(int i,int j){
// 	if(i<0 || j<0 || i==n || j==m) return;
// 	if(grid[i-1][j]=='@' && vis[i-1][j]==0) { /* up */
// 		vis[i-1][j]=1;
// 		floodfill(i-1,j);
// 	}
// 	if(grid[i+1][j]=='@' && vis[i+1][j]==0) { /* down */
// 		vis[i+1][j]=1;
// 		floodfill(i+1,j);
// 	}
// 	if(grid[i][j-1]=='@' && vis[i][j-1]==0) { /* left */
// 		vis[i][j-1]=1;
// 		floodfill(i,j-1);
// 	}
// 	if(grid[i][j+1]=='@' && vis[i][j+1]==0) { /* right */
// 		vis[i][j+1]=1;
// 		floodfill(i,j+1);
// 	}
// 	if(grid[i-1][j-1]=='@' && vis[i-1][j-1]==0) { /* upper-left corner */
// 		vis[i-1][j-1]=1;
// 		floodfill(i-1,j-1);
// 	}
// 	if(grid[i-1][j+1]=='@' && vis[i-1][j+1]==0) { /* upper-right corner */
// 		vis[i-1][j+1]=1;
// 		floodfill(i-1,j+1);
// 	}
// 	if(grid[i+1][j-1]=='@' && vis[i+1][j-1]==0) { /* lower-left corner */
// 		vis[i+1][j-1]=1;
// 		floodfill(i+1,j-1);
// 	}
// 	if(grid[i+1][j+1]=='@' && vis[i+1][j+1]==0) { /* lower-right corner */
// 		vis[i+1][j+1]=1;
// 		floodfill(i+1,j+1);
// 	}
// }
// int main(){
// 	int i,j,cnt;
// 	while(scanf("%d %d",&n,&m) && n){
// 		getchar();
// 		memset(vis,0,sizeof(vis));
// 		for(i=0;i<n;i++){
// 			for(j=0;j<m;j++){
// 				scanf("%c",&grid[i][j]);
// 			}
// 			getchar();
// 		}
// 		cnt=0;
// 		for(i=0;i<n;i++){
// 			for(j=0;j<m;j++){
// 				if(grid[i][j]=='@' && vis[i][j]==0){
// 					vis[i][j]=1;
// 					floodfill(i,j);
// 					cnt++;
// 				}
// 			}
// 		}
// 		printf("%d\n",cnt);
// 	}
// 	return 0;
// }


/*
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
*/