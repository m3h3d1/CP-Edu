//number of distinct stars
#include<bits/stdc++.h>
using namespace std;
string grid[105];
int vis[105][105];
int r, c;

int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};
int cnt=0;
void dfs(int a, int b) {
    vis[a][b] = 1;
    cnt++;
    for(int i=0;i<8;++i) {
        int y = dy[i]+a;
        int x = dx[i]+b;
        if(x>=0 && y>=0 && x<c && y<r && grid[y][x]=='*' && !vis[y][x]) {
            dfs(y, x);
        }
    }
}

int main() {
    int a,b,n,T,cas=0;
    while(cin>>r>>c && (r||c)) {
        cin.ignore();
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<r;++i) getline(cin, grid[i]);

        int res = 0;
        for(int i=0;i<r;++i) {
            for(int j=0;j<c;++j) {
                if(grid[i][j]=='*' && !vis[i][j]) {
                    cnt = 0;
                    dfs(i, j);
                    if(cnt == 1) res++;
                }
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}

/*
5 5
.....
....*
....*
...*.
*....
4 3
...
.*.
...
*.*
0 0
*/