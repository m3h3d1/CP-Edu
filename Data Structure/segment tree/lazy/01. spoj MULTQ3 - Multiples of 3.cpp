#include<bits/stdc++.h>
using namespace std;
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int mxn = 1e5+9;
struct Data {
    int one,two,zero;
    int lazy;
} st[mxn*4];

void rotate(int v) { // 1,2,0 -> 0,1,2 
    int tmp = st[v].two;
    st[v].two = st[v].one;
    st[v].one = st[v].zero;
    st[v].zero = tmp;
}
inline void change(int v, int val) {
    st[v].lazy += val;
    st[v].lazy %= 3;
}
void pushdown(int v) {
    change(v*2, st[v].lazy);
    change(v*2+1, st[v].lazy);
    for(int k=1;k<=st[v].lazy;++k) {
        rotate(v*2);
        rotate(v*2+1);
    }
    st[v].lazy=0;
}
void pushup(int v) {
    st[v].zero = st[v*2].zero + st[v*2+1].zero;
    st[v].one = st[v*2].one + st[v*2+1].one;
    st[v].two = st[v*2].two + st[v*2+1].two;
}
void update(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) {
        rotate(v);
        st[v].lazy++;
        st[v].lazy %= 3;
        return;
    }
    if(st[v].lazy) pushdown(v);
    int m = (l+r)/2;
    if(j<=m) update(lchild,i,j);
    else if(i>m) update(rchild,i,j);
    else {
        update(lchild,i,m);
        update(rchild,m+1,j);
    }
    pushup(v);
}

int query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v].zero;
    if(st[v].lazy) pushdown(v);
    int m = (l+r)/2;
    if(j<=m) return query(lchild,i,j);
    else if(i>m) return query(rchild,i,j);
    else {
        return query(lchild,i,m) + query(rchild,m+1,j);
    }
}
void build(int v, int l, int r) {
    if(l==r) {
        st[v].zero = 1;
        st[v].one = st[v].two = st[v].lazy = 0;
        return;
    }
    int m =(l+r)/2;
    build(lchild);
    build(rchild);
    pushup(v);
    st[v].lazy = 0;
}

int main() {
    int a,b,n,q,typ;
    scanf("%d %d",&n,&q);
    build(1,1,n);
    while(q--) {
        scanf("%d %d %d",&typ,&a,&b);
        a++, b++; //to 1 indexing
        if(typ==0) update(1,1,n,a,b);
        else {
            int res = query(1,1,n,a,b);
            printf("%d\n", res);
        }
    }
    return 0;
}

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