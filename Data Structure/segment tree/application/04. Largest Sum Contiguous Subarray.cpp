#include<bits/stdc++.h>
using namespace std;
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int mxn = 5e4+9;
#define ll long long
struct Data {
    ll sum, left, right, mx; //left->pref, right->suf
} st[mxn*4];
int A[mxn];

Data combine(Data a, Data b) {
    Data c;
    c.sum = a.sum + b.sum;
    c.left = max(a.left, a.sum+b.left);
    c.right = max(b.right, b.sum+a.right);
    c.mx = max(max(a.mx, b.mx), a.right+b.left);
    return c;
}
Data query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v];
    int m = (l+r)/2;
    if(j<=m) return query(lchild,i,j);
    else if(i>m) return query(rchild,i,j);
    else {
        Data a = query(lchild,i,m);
        Data b = query(rchild,m+1,j);
        return combine(a, b);
    }
}
void update(int v, int l, int r, int i, int val) {
    if(l==r) {
        st[v].sum = st[v].left = st[v].right = st[v].mx = val;
        return;
    }
    int m = (l+r)/2;
    if(i<=m) update(lchild,i,val);
    else update(rchild,i,val);
    st[v] = combine(st[v*2], st[v*2+1]);
}
void build(int v, int l, int r) {
    if(l==r) {
        st[v].sum = st[v].left = st[v].right = st[v].mx = A[l];
        return;
    }
    int m = (l+r)/2;
    build(lchild);
    build(rchild);
    st[v] = combine(st[v*2], st[v*2+1]);
} 

int main() {
    int n,q,a,b,val,typ;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&A[i]);
    build(1,1,n);
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&typ);
        if(typ==0) {
            scanf("%d %d",&a,&val);
            update(1,1,n,a,val);
        }
        else {
            scanf("%d %d",&a,&b);
            Data res = query(1,1,n,a,b);
            printf("%lld\n", res.mx);
        }
    }
    return 0;
}

/*
4
1 2 3 4
4
1 1 3
0 3 -3
1 2 4
1 3 3

8
-1 -2 3 4 5 6 -7 -8
5
1 8
1 3
1 4
*/

/*
spoj gss3
Input:
The first line of input contains an integer N. The following line contains N integers, representing the sequence A1..AN. 
The third line contains an integer M. The next M lines contain the operations in following form:
0 x y: modify Ax into y (|y|<=10000).
1 x y: print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }.
*/

/*
https://discuss.codechef.com/questions/96902/spoj-gss1-problem

Here's my attempt at explaining the approach. The problem is the maximum sum subarray problem, which you want to solve by a divide and conquer approach, which is what a segment tree does.

For a given range $A$, you split it into two pieces, the left half $L$ and the right half $R$. Naturally the maximum sum subarray in $A$ can lie either 1) completely in $L$, or lie 2) completely in $R$, or 3) cross over from $L$ to $R$. Solve recursively for the two halves. We get the maximum sum subarrays for the left half as $L.maxsum$ and the right half as $R.maxsum$, and now we know the first 2 of the 3 options just like that *snaps fingers* :P
How do we get the third option? A range that extends from $L$ to $R$ can be broken into a suffix of $L$ and a prefix of $R$. So if we know the maximum suffix sum in $L$ as $L.suffixsum$ and the maximum prefix sum in $R$ as $R.prefixsum$, the sum of those 2 values will give us the maximum sum subarray extending from $L$ to $R$, which covers option 3. So we get
tree[index].maxsum = max(max(tree[2*index+1].maxsum, tree[2*index+2].maxsum),
                     tree[2*index+1].suffixsum + tree[2*index+2].prefixsum);
Now since we have incorporated 2 new values (prefixsum and suffixsum), the parent range of $A$ will also require these from $A$. So now we need to calculate $A.prefixsum$ and $A.suffixsum$. The maximum sum prefix of $A$ can be 1) the maximum sum prefix of $L$, or 2) cover the whole of $L$ and extend into $R$. Option 1 is simply $L.prefixsum$, and option 2 is $\sum L + R.prefixsum$. Similarly, the maximum sum suffix of $A$ is either $R.suffixsum$ or $\sum R + L.suffixsum$. So now it seems we need another value to represent a range, which is the sum of that range. So we have
tree[index].prefixsum = max(tree[2*index+1].prefixsum,
                        tree[2*index+1].sum + tree[2*index+2].prefixsum);
tree[index].suffixsum = max(tree[2*index+2].suffixsum,
                        tree[2*index+2].sum + tree[2*index+1].suffixsum);
And for the sum it is simply
tree[index].sum = tree[2*index+1].sum + tree[2*index+2].sum;
Well, that covers the whole thing, I hope it is clear why we require the 4 values in one node of the segment tree. Also you can see that the calculation of tree[index].maxsum in the link you provided can be simplified as I have described above. Feel free to ask if anything is not clear :)
*/

/*
https://yuting-zhang.github.io/spoj/2017/02/02/SPOJ-GSS3.html

Problem: GSS3
Solution: Application of segment tree.

The hard part of this problem is to find what should be stored at each node in order to be able to merge data from left and right children and compute the maximum subsequence sum of the current node.

There are three cases.

The maximum subsequence sum only uses elements from the left child.
The maximum subsequence sum only uses elements from the right child.
The maximum subsequence sum uses elements from both children.
Let max_sum(p) be the maximum subsequence sum at node p, left, right be the left child and right child of p. Then the first two cases are simply max_sum(left) and max_sum(right))

For the third case, the resulting subsequence will consist of a suffix of the left child subsequence and a prefix of the right child subsequence. So we will need to store the information for that as well.

Let sum(p) be the subsequence sum at node p, left_sum(p) be the maximum prefix sum at node p, right_sum(p) be the maximum suffix sum at node p.

The whole merge process now becomes:

sum(p) = sum(left) + sum(right)
left_sum(p) = max(left_sum(left), sum(left) + left_sum(right))
right_sum(p) = max(right_sum(right), sum(right) + right_sum(left))
max_sum(p) = max(max(max_sum(left), max_sum(right)), right_sum(left) + left_sum(right))
*/