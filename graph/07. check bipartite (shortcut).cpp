#include<iostream>
using namespace std;

int main() {
	int a,b,n,e;
	while(cin>>n, n) {
		cin>>e;
		for(int i=0;i<e;++i) {
			cin>>a>>b;
		}
		if((n>e) || (n==e && n%2==0)) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
	}
	return 0;
}

/*
3
3
0 1
1 2
2 0

3
2
0 1
1 2

9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8

0
*/

/*
*** strongly connected graph

uva 10004 - Bicoloring

• no node will have an edge to itself.
• the graph is nondirected. That is, if a node a is said to be connected to a node b, then you must
assume that b is connected to a.
• the graph will be strongly connected. That is, there will be at least one path from any node to
any other node.
*/