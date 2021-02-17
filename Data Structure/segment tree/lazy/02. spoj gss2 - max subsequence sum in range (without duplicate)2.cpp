#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int mxn = 1e5+9;
const int M = 1e5;
int A[mxn], last[2*mxn];
ll sum[mxn*4], Max[mxn*4], lazy[mxn*4], prelazy[mxn*4];
struct Data {
    int l,r,id;
    ll ans;
} q[mxn];

void change(int v, int p) {
    Max[v] = max(Max[v], prelazy[p]+sum[v]);
    prelazy[v] = max(prelazy[v], prelazy[p]+lazy[v]);
    sum[v] += lazy[p];
    lazy[v] += lazy[p];
}
void push_down(int v) {
    if(lazy[v] || prelazy[v]) {
        change(v*2, v);
        change(v*2+1, v);
        lazy[v] = prelazy[v] = 0;
    }
}
void push_up(int v) {
    Max[v] = max(Max[v*2], Max[v*2+1]);
    sum[v] = max(sum[v*2], sum[v*2+1]);
}
ll query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return Max[v];
    push_down(v);
    int m=(l+r)/2;
    if(j<=m) return query(lchild,i,j);
    else if(i>m) return query(rchild,i,j);
    else return max(query(lchild,i,m), query(rchild,m+1,j));
}
void update(int v, int l, int r, int i, int j, ll x) {
    if(l>=i && r<=j) {
        sum[v] += x;
        lazy[v] += x;
        Max[v] = max(Max[v], sum[v]);
        prelazy[v] = max(prelazy[v], lazy[v]);
        return;
    }
    push_down(v);
    int m = (l+r)/2;
    if(j<=m) update(lchild,i,j,x);
    else if(i>m) update(rchild,i,j,x);
    else {
        update(lchild,i,m,x);
        update(rchild,m+1,j,x);
    }
    push_up(v);
}

int main() {
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&A[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;++i) {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].id = i;
    }
    sort(q+1,q+m+1,[](Data a, Data b) {
        return a.r<b.r;
    });
    int j=1;
    for(int i=1;i<=n;++i) {
        update(1,1,n,last[A[i]+M]+1,i,A[i]);
        last[A[i]+M] = i;
        while(j<=m && q[j].r==i) {
            q[q[j].id].ans = query(1,1,n,q[j].l,q[j].r);
            j++;
        }
    }
    for(int i=1;i<=m;++i) printf("%lld\n", q[i].ans);
    return 0;
}