#include<bits/stdc++.h>
using namespace std;
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
#define ll long long
const int mxn = 5e4+9;
struct Data {
    int a, b;
} seg[mxn];
int que[mxn], A[mxn*3], Asize; // A size is mxn*3 because of 3 types of elements -> seg.a, seg.b, que
int st[mxn*3*4], lazy[mxn*3*4];

void arrayCompress(int n, int q) {
    set<int> s;
    for(int i=1;i<=n;++i) {
        s.insert(seg[i].a);
        s.insert(seg[i].b);
    }
    for(int i=1;i<=q;++i) s.insert(que[i]);
    Asize = 0;
    for(auto x: s) {
        A[Asize++] = x;
    }
}
inline int compressedValue(int x) {
    return lower_bound(A, A+Asize, x) - A;
}
void build(int v, int l, int r) {
    st[v] = lazy[v] = 0;
    if(l==r) return;
    int m = (l+r)/2;
    build(lchild);
    build(rchild);
}
inline void change(int v, int l, int r, int val) {
    st[v] += val * (r-l+1);
    if(l!=r) lazy[v] += val;
}
void pushdown(int v, int l, int r) {
    int m = (l+r)/2;
    change(lchild, lazy[v]);
    change(rchild, lazy[v]);
    lazy[v] = 0;
}
inline void pushup(int v) {
    st[v] = st[v*2] + st[v*2+1];
}
void update(int v, int l, int r, int i, int j, int val) {
    if(l>=i && r<=j) {
        change(v,l,r,val);
        return;
    }
    if(lazy[v]) pushdown(v,l,r);
    int m = (l+r)/2;
    if(j<=m) update(lchild,i,j,val);
    else if(i>m) update(rchild,i,j,val);
    else {
        update(lchild,i,m,val);
        update(rchild,m+1,j,val);
    }
    pushup(v);
}
int query(int v, int l, int r, int i) {
    if(l>=i && r<=i) return st[v];
    if(lazy[v]) pushdown(v,l,r);
    int m = (l+r)/2;
    if(i<=m) return query(lchild,i);
    else return query(rchild,i);
}

int main() {
    int a,b,n,q,T,cas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;++i) {
            scanf("%d %d",&seg[i].a,&seg[i].b);
        }
        for(int i=1;i<=q;++i) scanf("%d",&que[i]);
        arrayCompress(n,q);
        build(1,1,Asize);

        //updates
        for(int i=1;i<=n;++i) {
            a = compressedValue(seg[i].a);
            b = compressedValue(seg[i].b);
            a++, b++; //1 indexing
            update(1,1,Asize,a,b,1);
        }

        //queries
        printf("Case %d:\n", ++cas);
        for(int i=1;i<=q;++i) {
            a = compressedValue(que[i]);
            a++;
            int res = query(1,1,Asize,a);
            printf("%d\n", res);
        }
    }
    return 0;
}

/*
1

5 4

6 12
8 8
10 12
8 11
0 12

11
12
2
20
*/

/*
Given n segments (1 dimensional) and q points, for each point you have to find the number of segments which contain that point. A point pi will lie in a segment A B if A ≤ pi ≤ B.

For example, if the segments are (6 12), (8 8), (10 12), (8 11), (0 12) and the point is 11, then it is contained by 4 segments.

Input:
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case starts with a line containing two integers n (1 ≤ n ≤ 50000) and q (1 ≤ q ≤ 50000).

Each of the next n lines contains two integers Ak Bk (0 ≤ Ak ≤ Bk ≤ 108) denoting a segment.

Each of the next q lines contains an integer denoting a point. Each of them range in [0, 108].

Output:
For each case, print the case number in a single line. Then for each point, print the number of segments that contain that point.
*/