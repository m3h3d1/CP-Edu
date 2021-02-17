#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1e9;

void display(vector<int> &d) {
	for(int i=1;i<=n;++i) {
		printf("%d ",d[i]);
	}
} 
int bellman()
{
    vector<int> d (n, INF);
    d[v] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);
    
    for(int i=0;i<m;++i) { //check if negative cycle exists
    	if(d[e[i].a] + d[e[i].cost] < d[e[i].b]) {
    		cout<<"Negative cycle exists\n";
    		return 0;
    	}
    }
    // display d, for example, on the screen
    display(d);
    return 1;
}
int main() {
	cin>>n>>m;
	for(int i=0;i<m;++i) {
		edge x;
		cin>>x.a>>x.b>>x.cost;
		e.push_back(x);
	}
	cin>>v; //starting vertex
	bellman();
	return 0;
}

/*
4 4

3 2 -10
4 3 3
1 4 5
1 2 4

1
*/
/*
3 3

2 1 -6
1 3 3
3 2 2
1
*/

/*
BELLMAN-FORD (G, w, s)
	INITIALIZE-SINGLE-SOURCE (G, s)
	for each vertex i = 1 to V[G] - 1 do
	    for each edge (u, v) in E[G] do
	        RELAX (u, v, w)
	For each edge (u, v) in E[G] do
	    if d[u] + w(u, v) < d[v] then
	        return FALSE
	return TRUE
 
Analysis:
The initialization in line 1 takes  (v) time
For loop of lines 2-4 takes O(E) time and For-loop of line 5-7 takes O(E) time.
Thus, the Bellman-Ford algorithm runs in O(E) time.
*/