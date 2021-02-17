#include<bits/stdc++.h>
using namespace std;
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
#define x first // value
#define y second //frequency
const int mxn = 1e5+9;
struct Data {
    pair<int, int> mx;
    pair<int, int> left;
    pair<int, int> right;
    inline void reset() {
        mx.x = mx.y = left.x = left.y = right.x = right.y = 0;
    }
} st[mxn*4];
int A[mxn];

Data combine(Data a, Data b) {
    Data res;
    if(a.left.x == b.right.x) {
        res.mx.x = res.left.x = res.right.x = a.left.x;
        res.mx.y = res.left.y = res.right.y = a.left.y + b.right.y;
    }
    else {
        // update res.left, res.right
        res.left = a.left;
        res.right = b.right;
        if(a.left.x == b.left.x) {
            res.left.y = a.left.y + b.left.y;
        }
        if(a.right.x == b.right.x) {
            res.right.y = a.right.y + b.right.y;
        }

        // update res.mx
        res.mx = (a.mx.y > b.mx.y) ? a.mx : b.mx;
        if(a.right.x == b.left.x) {  
            int tmp = a.right.y + b.left.y;
            if(tmp>res.mx.y) {
                res.mx.x = a.right.x;
                res.mx.y = tmp;
            }
        }
    }
    return res;
}
Data query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v];
    int m = (l+r)/2;
    if(j<=m) return query(lchild, i, j);
    else if(i>m) return query(rchild, i, j);
    else {
        Data a = query(lchild, i, m);
        Data b = query(rchild, m+1, j);
        return combine(a, b);
    }
}
void debugst(int v, int l, int r) {
    printf("%d -> (%d %d) -> ", v,l,r);
    printf("{(%d %d) (%d %d) (%d %d)}\n", st[v].mx.x, st[v].mx.y, st[v].left.x, st[v].left.y, st[v].right.x, st[v].right.y);
    if(l==r) return;
    int m=(l+r)/2;
    debugst(lchild);
    debugst(rchild);
}
void build(int v, int l, int r) {
    if(l==r) {
        st[v].mx = st[v].left = st[v].right = {A[l], 1};
        return;
    }
    int m = (l+r)/2;
    build(lchild);
    build(rchild);
    st[v] = combine(st[v*2], st[v*2+1]);
}
int main() {
    int n, q, a, b;
    while(scanf("%d",&n) && n) {
        for(int i=0;i<4*n;++i) {
            st[i].reset();
        }
        scanf("%d",&q);
        for(int i=1;i<=n;++i) scanf("%d",&A[i]);
        build(1,1,n);
        debugst(1,1,n);
    
        while(q--) {
            scanf("%d %d",&a,&b);
            Data res = query(1,1,n,a,b);
            printf("%d\n", res.mx.y);
        }
    }
    return 0;
}

/*
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
*/