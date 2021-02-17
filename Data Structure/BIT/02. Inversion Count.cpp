#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn = 2e5+9;
int n, BIT[mxn];
struct data {
    int val, id;
} A[mxn];

int cmp(data a, data b) {
    return a.val>b.val;
}
void update(int idx, int x) {
    for(int i=idx;i<=n;i+=i&(-i)) {
        BIT[i] += x;
    }
}
int get(int idx) {
    int s=0;
    for(int i=idx;i>0;i-=i&(-i)) {
        s += BIT[i];
    }
    return s;
}
int main() {
    int a,b,T,cas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        fill(BIT,BIT+n+3,0);
        for(int i=1;i<=n;++i) {
            scanf("%d",&A[i].val);
            A[i].id = i;
        }
        sort(A+1, A+n+1, cmp);

        ll inv = 0;
        for(int i=1;i<=n;++i) {
            int s = get(A[i].id);
            inv += s;
            update(A[i].id, 1);
        }
        printf("%lld\n", inv);
    }
    return 0;
}

/*
Inversion Count : SPOJ - INVCNT

Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. 
Given n and an array A your task is to find the number of inversions of A.

Test case:
2

3
3
1
2

5
2
3
8
6
1
*/