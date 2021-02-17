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
    
        while(q--) {
            scanf("%d %d",&a,&b);
            Data res = query(1,1,n,a,b);
            printf("%d\n", res.mx.y);
        }
    }
    return 0;
}

/*
SPOJ : FREQUENT - Frequent values

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10

0
*/

/*
You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). For each query, determine the most frequent value among the integers ai , ... , aj.

Input Specification:
The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a1 , ... , an (-100000 ≤ ai ≤ 100000, for each i ∈ {1, ..., n}) separated by spaces. You can assume that for each i ∈ {1, ..., n-1}: ai ≤ ai+1. The following q lines contain one query each, consisting of two integers i and j (1 ≤ i ≤ j ≤ n), which indicate the boundary indices for the query.

The last test case is followed by a line containing a single 0.

Output Specification:
For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.
*/

/*
In each node of segment tree (corresponding to interval [l,r]) we keep track 3 information : (Max_Frequent,Value_have_maxFrequent), (Frequent_of_a[l],a[l] ~ leftmost element), (Frequent_of_a[r],a[r] ~ rightmost element).

(Because the sequence is non decrease so at most one element of [l,r] can lie on both left son (aka [l,(l+r)/2]) and right son on segment tree, so we must keep track left most and rightmost element of each interval for the case this element exist)

The main problem is how to combine two son LEFT [l,(l+r)/2] and RIGHT [(l+r)/2+1,r], other function is similar to normal segment tree. It's easy but have some special case.
*/