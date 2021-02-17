#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 2e5+7;
vector<int> adj[N+9];
int lvl[N+9], subtreeSiz[N+9], cost[N+9];

void dfs(int on, int par) {
    subtreeSiz[on] = 1;
    for(int to: adj[on]) if(to!=par) {  // edges are bi-directional; we can also use vis[] array here instead of to!=par
        lvl[to] = lvl[on]+1;
        dfs(to, on);
        subtreeSiz[on] += subtreeSiz[to];
    }
}

int main() {
    int a,b,n;
    cin>>n;
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        a--, b--; // 0 indexed
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for(int i=0;i<n;++i) {
    	cout<<"Node:"<<i+1<<" level:"<<lvl[i]<<" Subtree size:"<<subtreeSiz[i]<<endl;
    }
    return 0;
}

/*
8
7 5
1 7
6 1
3 7
8 3
2 1
4 5

Tree:
			  1
		   /  \  \
		 7    2	  6
	   / \
	  5   3
	 /     \
	4       8
*/