#include<iostream>
#include<vector>
using namespace std;
vector<int> *adj;
bool *visited,*dfsVis;

int dfs(int x) {
	visited[x]=1;
	dfsVis[x]=1;

	//recursive call to all the adjacent vertices
	for(int i=0;i<adj[x].size();++i) {
		if(!visited[adj[x][i]] && dfs(adj[x][i]))
			return 1;
		else if(dfsVis[adj[x][i]])
			return 1;
	}

	//if reached here means cycle has not found in DFS from this vertex
	//reset
	dfsVis[x]=0;
	return 0;
}
int iscycle(int n) {
	visited=new bool[n];
	dfsVis=new bool[n];
	for(int i=0;i<n;++i) {
		if(dfs(i)) return 1;
	}
	return 0;
}
int main() {
	int a,b,n,m;
	cin>>n>>m;
	adj=new vector<int> [n];
	for(int i=0;i<m;++i) {
		cin>>a>>b;
		adj[a].push_back(b);
	}
	cout<<iscycle(n);
	return 0;
}
/*
@ Visited[] is used to keep track of already visited 
	vertices during the DFS is never gets
@ Recursion stack[] is used to keep track of visiting vertices 
	during DFS from particular vertex and gets reset once cycle is 
	not found from that vertex and will try DFS from other vertices.
*/

/*
4 4

0 1
1 2
2 3
3 1
*/


/*
https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool cycle(int u, vector<vector<int>> &adj, vector<int> &vis, vector<int> &inStack) {
        vis[u] = 1;
        inStack[u] = 1;
        for(int v: adj[u]) {
            if(inStack[v]) return 1;
            if(!vis[v] && cycle(v, adj, vis, inStack))
                return 1;
        }
        inStack[u] = 0;
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int> x: prerequisites) {
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(numCourses), inStack(numCourses);
        for(int i=0;i<numCourses;++i) {
            if(!vis[i] && cycle(i, adj, vis, inStack))
                return 0;
        }
        return 1;
    }
};
*/