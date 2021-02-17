#include<bits/stdc++.h>
using namespace std;
#define mxn 100005
#define ll long long
ll st[mxn*4], lazy[mxn*4];

void push(int v, int l, int r) {
    if(l == r) return;
    int m = (l+r)/2;
    lazy[v*2] += lazy[v];
    st[v*2] += lazy[v] * (m-l+1);
    lazy[v*2+1] += lazy[v];
    st[v*2+1] += lazy[v] * (r-m);
    lazy[v] = 0;
}
void update(int v, int l, int r, int i, int j, int val) {
    if(l>=i && r<=j) { 
        st[v] += (ll) val * (r-l+1);
        lazy[v] += val;
        return;
    }
    push(v, l, r);
    int m = (l+r)/2;
    if(j<=m) update(v*2, l, m, i, j, val);
    else if(i>m) update(v*2+1, m+1, r, i, j, val);
    else {
        update(v*2, l, m, i, m, val);
        update(v*2+1, m+1, r, m+1, j, val);
    }
    st[v] = st[v*2] + st[v*2+1];
}
ll query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v];
    push(v, l, r);
    int m = (l+r)/2;
    if(j<=m) return query(v*2, l, m, i, j);
    else if(i>m) return query(v*2+1, m+1, r, i, j);
    else return query(v*2, l, m, i, m) + query(v*2+1, m+1, r, m+1, j);
}
int main() {
    int a,b,n,q,check,val,T;
    scanf("%d",&T);
    while(T--) {
        for(int i=0;i<=4*n;++i) lazy[i] = st[i] = 0;
        scanf("%d %d",&n,&q);
        while(q--) {
            scanf("%d",&check);
            if(check==0) {
                scanf("%d %d %d", &a, &b, &val);
                update(1,1,n,a,b,val);
            }
            else {
                scanf("%d %d", &a, &b);
                ll x = query(1,1,n,a,b);
                printf("%lld\n", x);
            }
        }
    }
    return 0;
}

/*
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
*/