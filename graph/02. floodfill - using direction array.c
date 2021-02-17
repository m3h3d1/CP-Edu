#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
string str[25];
int visited[25][25];
int cnt,h,w;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void dfs(int a, int b) {
	visited[a][b]=1;
	cnt++;
	for(int i=0;i<4;++i) {
		int x=dx[i]+a;
		int y=dy[i]+b;
		if(x>=0 && y>=0 && x<h && y<w && str[x][y]!='#' && !visited[x][y]) {
			dfs(x,y);
		}
	}
}
int main() {
	int a,b,n,T,cas=0;
	cin>>T;
	while(T--) {
		cnt=0;
		memset(visited,0,sizeof(visited));
		cin>>w>>h;
		cin.ignore();
		for(int i=0;i<h;++i) {
			getline(cin,str[i]);
		}
		for(int i=0;i<h;++i) {
			for(int j=0;j<w;++j) {
				if(str[i][j]=='@') {
					dfs(i,j);
				}
			}
		}
		printf("Case %d: %d\n",++cas,cnt);
	}
	return 0;
}

/*
4

6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.

11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........

11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..

7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/