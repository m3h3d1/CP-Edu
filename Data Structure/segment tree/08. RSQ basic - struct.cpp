#include<bits/stdc++.h>
using namespace std;
#define mxn 500005
#define ll long long
struct node {
	ll s = 0;
	inline void set(ll val) {
		s = val;
	}
	inline void combine(node &a, node &b) {
		s = a.s + b.s;
	}
} st[mxn*4];
int A[mxn];

void build(int v, int l, int r) {
	if(l==r) {
		st[v].set(A[l]); return;
	}
	int m = (l+r)/2;
	build(v*2, l, m);
	build(v*2+1, m+1, r);
	st[v].combine(st[v*2], st[v*2+1]);
}
void update(int v, int l, int r, int i, int val) {
	if(l==r) {
		st[v].set(val);
		return;
	}
	int m = (l+r)/2;
	if(i<=m) update(v*2, l, m, i, val);
	else update(v*2+1, m+1, r, i, val);
	st[v].combine(st[v*2], st[v*2+1]);
}
node query(int v, int l, int r, int i, int j) {
	if(l>=i && r<=j) return st[v];
	int m = (l+r)/2;
	if(j<=m) return query(v*2, l, m, i, j);
	else if(i>m) return query(v*2+1, m+1, r, i, j);
	
	node a = query(v*2, l, m, i, m);
	node b = query(v*2+1, m+1, r, m+1, j);
	node ret;
	ret.combine(a, b);
	return ret;
}
int main() {
	int a,b,n,q;
	char str[2];
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i) {
		scanf("%d",&A[i]);
	}
	build(1,1,n);

	while(q--) {
		scanf("%s %d %d",str, &a, &b);
		if(str[0]=='=') update(1,1,n,a,b);
		else {
			node x = query(1,1,n,a,b);
			printf("%lld\n", x.s);
		}
	}
	return 0;
}

/*
st 2-B
154 ms

3 3
1 2 3
? 1 3
= 3 2
? 1 3
*/