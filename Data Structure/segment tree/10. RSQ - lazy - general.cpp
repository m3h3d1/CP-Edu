#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
#define ll long long
ll st[4*N], lazy[4*N];

void change(int v, int l, int r, ll val) {
    st[v] += val * (r-l+1);
    lazy[v] += val;
}
void push(int v, int l, int r) {
    int m = (l+r)/2;
    change(2*v, l, m, lazy[v]);
    change(2*v+1, m+1, r, lazy[v]);
    lazy[v] = 0;
}
void update(int v, int l, int r, int i, int j, int val) {
    if(l>=i && r<=j) {
        change(v, l, r, val);
        return;
    }
    push(v, l, r); //if(lazy[v])
    int m = (l+r)/2;
    if(j<=m) update(2*v, l, m, i, j, val);
    else if(i>m) update(2*v+1, m+1, r, i, j, val);
    else {
    	update(v*2, l, m, i, m, val);
    	update(v*2+1, m+1, r, m+1, j, val);
    }
    st[v] = st[2*v] + st[2*v+1];
}
ll query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v];
    push(v, l, r); //if(lazy[v])
    int m = (l+r)/2;
    if(j<=m) return query(v*2, l, m, i, j);
    else if(i>m) return query(v*2+1, m+1, r, i, j);
    else return query(2*v, l, m, i, j) + query(2*v+1, m+1, r, i, j);
}
int main() {
    int a,b,n,T,cas=0,q,typ,val;
    scanf("%d",&T);
    while(T--) {
    	scanf("%d %d",&n,&q);
    	fill(st, st+4*n+3, 0);
    	fill(lazy, lazy+4*n+3, 0);
    	while(q--) {
    		scanf("%d",&typ);
    		if(typ==0) {
    			scanf("%d %d %d",&a, &b, &val);
    			update(1, 1, n, a, b, val);
    		}
    		else {
    			scanf("%d %d",&a, &b);
    			ll x = query(1, 1, n, a, b);
    			printf("%lld\n", x);
    		}
    	}
    }
    return 0;
}

/*
Horrible Queries: SPOJ - HORRIBLE 

1

8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
*/