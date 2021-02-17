//kahn's algorithm
#include<iostream>
using namespace std;
#define mxn 100
int take[mxn][mxn],indegree[mxn],list[mxn];
int used[mxn];

// when take[a][b] = 1, that means a must come before b
// indegree[i] = number of items that that must come before i
// when taken[i] = 1, means we already have taken ith item
int topsort(int n) {
	for(int i=0;i<n;++i) {
		int j;
		for(j=0;j<n;++j) if(!indegree[j] && !used[j]) {
			used[j]=1;
			list[i]=j;
			// in this step we are taking item j
			// we'd update the indegree[k] of items that depended on j
			for(int k=0;k<n;++k) {
				if(take[j][k] && !used[k]) --indegree[k];
			}
			break;
		}
		if(j==n) return 0;
	}
	return 1;
}
int main() {
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;++i) {
		cin>>a>>b;
		take[a][b]=1;
		indegree[b]++;
	}
	if(topsort(n)) {
		for(int i=0;i<n;++i) cout<<list[i]<<" ";
	}
	else cout<<"No solution. There exists a cycle in the graph"<<endl;
	return 0;
}

/*
6 6

5 2
5 0
4 0
4 1
2 3
3 1
*/