#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn = 1e4+9;
int BIT[mxn];
int n;

void update(int i, int val) {
    for(;i<=n;i+=i&(-i)) {
        BIT[i]+=val;
    }
}
ll query(int i) {
    ll s = 0;
    for(;i>0;i-=i&(-i)) {
        s+=BIT[i];
    }
    return s;
}
int main() {
    int l,r,u,q,x,T,val;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&u);
        fill(BIT,BIT+n+1,0);
        while(u--) {
            scanf("%d %d %d",&l,&r,&val);
            l++, r++; // 1 based indexing
            update(l, val);
            update(r+1, -val);
        }
        scanf("%d",&q);
        while(q--) {
            scanf("%d",&x);
            x++;
            ll sum = query(x);
            printf("%lld\n", sum);
        }
    }
    return 0;
}

/*
Update The Array : SPOJ UPDATEIT

1
5 3
0 1 7
2 4 6
1 3 2
3
0
3
4
*/

/*
https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
*/