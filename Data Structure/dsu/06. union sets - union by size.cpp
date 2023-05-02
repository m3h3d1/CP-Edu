#include "bits/stdc++.h"
using namespace std;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
#define ll long long
vector<int> par, siz;

int findPar(int u) {
	if(par[u]==u) return u;
	return par[u] = findPar(par[u]);
}
void merge(int a, int b) {
	a = findPar(a);
	b = findPar(b);
	if(a!=b) {
		if(siz[a] < siz[b]) swap(a, b);
		par[b] = a;
		siz[a] += siz[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int a,b,n,T,cas=0;
	n=7;
	par.resize(n+1);
	siz.resize(n+1);
	for(int i=1;i<=n;++i) {
		par[i] = i;
		siz[i] = 1;
	}
	merge(1, 3);
	merge(2, 3);
	merge(5, 2);
	merge(4, 6);
	merge(7, 6);
	for(int i=1;i<=n;++i) {
		cout<<findPar(i)<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;++i) {
		cout<<par[i]<<" "<<siz[i]<<endl;
	}
	return 0;
}