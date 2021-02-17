#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int mxn = 1e5+9;
const int M = 1e5;
int A[mxn], vis[mxn*2];
ll MAX[mxn*4], lazy[mxn*4], prelazy[mxn*4], sum[mxn*4];
struct Data {
    int l, r, id;
    ll ans;
} q[mxn];

void change(int v, int p) {
    MAX[v] = max(MAX[v], prelazy[p]+sum[v]);
    prelazy[v] = max(prelazy[v], prelazy[p]+lazy[v]);
    sum[v]+=lazy[p];
    lazy[v]+=lazy[p];
}
void push_down(int v) {
    if(lazy[v] || prelazy[v]) { // to speed up
        change(v*2,v);
        change(v*2+1,v);

        lazy[v] = prelazy[v] = 0;
    }
}
void push_up(int v) {
    MAX[v] = max(MAX[v*2], MAX[v*2+1]);
    sum[v] = max(sum[v*2], sum[v*2+1]);
}
ll query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return MAX[v];
    push_down(v);
    int m = (l+r)/2;
    ll res;
    if(j<=m) res = query(lchild,i,j);
    else if(i>m) res = query(rchild,i,j);
    else {
        ll a = query(lchild,i,m);
        ll b = query(rchild,m+1,j);
        res = max(a,b);
    }
    return res;
}
void update(int v, int l, int r, int i, int j, ll x) {
    if(l>=i && r<=j) {
        sum[v]+=x;
        lazy[v]+=x;
        MAX[v] = max(MAX[v], sum[v]);
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
void build(int v, int l, int r) {
    MAX[v] = lazy[v] = prelazy[v] = sum[v] = 0;
    if(l==r) return;
    int m = (l+r)/2;
    build(lchild);
    build(rchild);
    push_up(v);
}

int main() {
    int n,m;
    scanf("%d",&n);
    fill(vis,vis+mxn*2,0);
    for(int i=1;i<=n;++i) scanf("%d",&A[i]);
    build(1,1,n); // innitialized the tree with 0
    scanf("%d",&m);

    //offline query
    for(int i=1;i<=m;++i) {
        scanf("%d %d",&q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q+1,q+m+1,[](Data a, Data b) {
        return a.r<b.r;
    });
    int j=1;
    for(int i=1;i<=n;++i) {
        update(1,1,n,vis[A[i]+M]+1,i,A[i]);
        vis[A[i]+M] = i;
        while(j<=m && q[j].r==i) {
            q[q[j].id].ans = query(1,1,n,q[j].l, q[j].r);
            j++;
        }
    }
    for(int i=1;i<=m;++i) 
        printf("%lld\n", q[i].ans);
    return 0;
}

/*
Input
    Line 1: integer N (1 <= N <= 100000);
    Line 2: N integers denoting the score of each problem, each of them is a integer in range [-100000, 100000];
    Line 3: integer Q (1 <= Q <= 100000);
    Line 3+i (1 <= i <= Q): two integers X and Y denoting the ith question.
Output
    Line i: a single integer, the answer to the ith question.

Sample Test:
9
4 -2 -2 3 -1 -4 2 2 -6
3
1 2
1 5
4 9
*/

/*
spoj - gss2

Problem: Given a array of numbers a[1...n] (where duplicates are allowed), and a query range [x,y].
query(x,y) should return the sub-sequence sum, whose sum is maximum in the range [x,y] by satisfying uniqueness criteria.

To give you an array of length n, there are q queries. Each query gives an interval [X,Y]. You are asked to find MAX:{sum [i, j]} (X<=i<=j<=Y). At the same time, when the interval summation occurs, if a number occurs many times, then the sum is calculated only once.

Topic idea: Usually we use line segment tree to solve the problem of finding the maximum subsection and interval, but this problem needs to solve the problem of number repetition.

To solve this problem, an off-line operation can be carried out, using a vis[a[i] (a[i] may be negative, so remember to add 100000) array to store the location of the last occurrence of a[i] number, and then use only the interval of [vis[a[i], i] plus a[i] for each update and sum.

Then the queries are sorted according to the right endpoint of the interval, which is updated and solved at the same time.

Four values are stored in the segment tree

MAX: Storing the Optimal Solution of the Current Interval

sum: Stores the maximum of the current interval

lazy: lazy flag used to record downloaded values

prelazy: The second lazy flag that records the maximum download value

Why do we use two lazy markers here? The first one is for normal interval update operation, while the second one is for updating the optimal solution, such as - 5 in an interval, but there is a lazy marker 5 in his left son. For his left son, adding 5 directly is the optimal solution.

https://programmer.group/spoj-gss2-can-you-answer-these-queries-ii-segment-tree.html
http://tiny-code.blogspot.com/2013/07/spoj-1557can-you-answer-these-queries-ii.html
*/