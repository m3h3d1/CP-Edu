#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int N = 1e5+9;
struct node {
    int one, two, zero, lazy;
    node operator + (const node &a) const {
        node c;
        c.zero = zero + a.zero;
        c.one = one + a.one;
        c.two = two + a.two;
        return c;
    }
} st[N*4];

void rotate(int v) {
    int tmp = st[v].zero;
    st[v].zero = st[v].two;
    st[v].two = st[v].one;
    st[v].one = tmp;
}
void pushdown(int v) {
    st[v*2].lazy += st[v].lazy;
    st[v*2+1].lazy += st[v].lazy;
    for(int i=1;i<=st[v].lazy%3;++i) {
        rotate(v*2);
        rotate(v*2+1);
    }
    st[v].lazy = 0;
}
void pushup(int v) {
    st[v].zero = st[v*2].zero + st[v*2+1].zero;
    st[v].one = st[v*2].one + st[v*2+1].one;
    st[v].two = st[v*2].two + st[v*2+1].two;
}
void update(int v, int l, int r, int i, int j, ll x) {
    if(l>=i && r<=j) {
        rotate(v);
        st[v].lazy++;
        return;
    }
    if(st[v].lazy) pushdown(v);
    int m = (l+r)/2;
    if(j<=m) update(lchild, i, j, x);
    else if(i>m) update(rchild, i, j, x);
    else {
        update(lchild, i, m, x);
        update(rchild, m+1, j, x);
    }
    pushup(v);
}
node query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v];
    if(st[v].lazy) pushdown(v);
    int m = (l+r)/2;
    if(j<=m) return query(lchild, i, j);
    else if(i>m) return query(rchild, i, j);
    else {
        node a = query(lchild, i, m);
        node b = query(rchild, m+1, j);
        return a+b;
    }
}
void build(int v, int l, int r) {
    st[v].lazy = 0;
    if(l==r) {
        st[v].zero=1;
        st[v].one = st[v].two = st[v].lazy = 0;
        return;
    }
    int m = (l+r)/2;
    build(lchild);
    build(rchild);
    pushup(v);
}

int main() {
    int a, b, n, q, typ;
    scanf("%d %d",&n, &q);
    build(1,1,n);
    while(q--) {
        scanf("%d %d %d",&typ, &a, &b);
        ++a, ++b;
        if(typ==0) {
            update(1,1,n,a,b,1);
        }
        else {
            node res = query(1,1,n,a,b);
            printf("%d\n", res.zero);
        }
    }
    return 0;
}

/*
Submitted
27-06-2020
*/

/*
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3
*/

/*
There are N numbers a[0],a[1]..a[N - 1]. Initally all are 0. You have to perform two types of operations :

1) Increase the numbers between indices A and B (inclusive) by 1. This is represented by the command "0 A B"
2) Answer how many numbers between indices A and B (inclusive) are divisible by 3. This is represented by the command "1 A B".

Input
The first line contains two integers, N and Q. Each of the next Q lines are either of the form "0 A B" or "1 A B" as mentioned above.

Output
Output 1 line for each of the queries of the form "1 A B" containing the required answer for the corresponding query.
*/