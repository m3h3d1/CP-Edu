#include<bits/stdc++.h>
using namespace std;
#define lchild v*2,l,m
#define rchild v*2+1,m+1,r
const int mxnn = 3e4+9;
const int mxnq = 2e5+9;
struct Data {
    int l,r,id;
    int res;
    bool operator<(const Data other) {
        return r<other.r;
    }
} qs[mxnq];
int st[mxnn*4], A[mxnn], last[1000009];

void update(int v, int l, int r, int i, int val) {
    if(l==r) {
        st[v] = val;
        return;
    }
    int m = (l+r)/2;
    if(i<=m) update(lchild,i,val);
    else update(rchild,i,val);
    st[v] = st[v*2] + st[v*2+1];
}
int query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v];
    int m = (l+r)/2;
    if(j<=m) return query(lchild,i,j);
    else if(i>m) return query(rchild,i,j);
    else {
        return query(lchild,i,m) + query(rchild,m+1,j);
    }
}

int main() {
    int n,q,m;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&A[i]);
    }

    //offline query
    scanf("%d",&m);
    for(int i=1;i<=m;++i) {
        scanf("%d %d",&qs[i].l,&qs[i].r);
        qs[i].id = i;
    }
    sort(qs+1,qs+m+1);
    int j=1;
    for(int i=1;i<=n;++i) {
        if(last[A[i]]!=0) update(1,1,n,last[A[i]],0); //if found previously
        update(1,1,n,i,1);
        last[A[i]] = i;
        while(j<=m && qs[j].r==i) {
            qs[qs[j].id].res = query(1,1,n,qs[j].l,qs[j].r);
            j++;
        }
    }

    for(int i=1;i<=m;++i) {
        printf("%d\n", qs[i].res);
    }
    return 0;
}