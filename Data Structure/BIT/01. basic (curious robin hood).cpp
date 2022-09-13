#include<bits/stdc++.h>
using namespace std;
int A[100005], bit[100005];
int n;

int query(int i) {
    int s=0;
    for(;i>0;i-=(i&-i)) {
        s+=bit[i];
    }
    return s;
}
void update(int i, int val) {
    for(;i<=n;i+=(i&-i)) {
        bit[i] += val;
    }
}
int main() {
    int a,b,T,cas=0, idx, val,q,typ;
    scanf("%d",&T);
    while(T--) {
        printf("Case %d:\n", ++cas);
        scanf("%d %d",&n,&q);
        fill(bit, bit+n+2, 0);

        for(int i=1;i<=n;++i) {
            scanf("%d",&A[i]);
            update(i, A[i]);
        }
        while(q--) {
            scanf("%d",&typ);
            if(typ==1) {
                scanf("%d",&idx);
                idx++; //1 indexing
                update(idx, -A[idx]);
                printf("%d\n", A[idx]);
                A[idx] = 0;
            }
            else if(typ==2) {
                scanf("%d %d",&idx, &val);
                update(++idx, val);
                A[idx]+=val;
            }
            else {
                scanf("%d %d",&a, &b);
                printf("%d\n", query(++b)-query(++a-1));
            }
        }
    }
    return 0;
}

/*
1

5 6
3 2 1 4 5
1 4
2 3 4
3 0 3
1 2
3 0 4
1 1
*/


/*
Curious Robin Hood: LightOJ - 1112 

Now each time he can he can do one of the three tasks.

1)                  Give all the money of the ith sack to the poor, leaving the sack empty.

2)                  Add new amount (given in input) in the ith sack.

3)                  Find the total amount of money from ith sack to jth sack.
*/