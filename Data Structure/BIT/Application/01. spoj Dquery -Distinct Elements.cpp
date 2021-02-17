#include<bits/stdc++.h>
using namespace std;
const int mxn = 3e4+9;
const int mxq = 2e5+9;
struct Data {
    int l, r, id, res;
    bool operator<(const Data other) {
        return r<other.r;
    }
} qs[mxq];
int A[mxn], BIT[mxn], last[1000009];
int n;

int query(int i) {
    int s=0;
    for(;i>0;i-=i&(-i)) s+=BIT[i];
    return s;
}
void update(int i, int val) {
    for(;i<=n;i+=i&(-i)) BIT[i]+=val; 
}
int main() {
    int m;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&A[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;++i) {
        scanf("%d %d",&qs[i].l,&qs[i].r);
        qs[i].id = i;
    }
    sort(qs+1,qs+m+1);

    int j=1;
    for(int i=1;i<=n;++i) {
        if(last[A[i]]) update(last[A[i]],-1);
        update(i,1);
        last[A[i]] = i;
        while(j<=m && qs[j].r==i) {
            qs[qs[j].id].res = query(qs[j].r)-query(qs[j].l-1);
            j++;
        }
    }

    for(int i=1;i<=m;++i) {
        printf("%d\n", qs[i].res);
    }
    return 0;
}