#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn = 5e4+9;
struct Data {
    int a, b;
} seg[mxn];
int que[mxn], A[mxn*3], Asize;
int BIT[mxn*3];

void arrayCompress(int n, int q) {
    set<int> s;
    for(int i=1;i<=n;++i) {
        s.insert(seg[i].a);
        s.insert(seg[i].b);
    }
    for(int i=1;i<=q;++i) s.insert(que[i]);
    Asize = 0;
    for(auto x: s) {
        A[Asize++] = x;
    }
}
inline int compressedValue(int x) {
    return lower_bound(A, A+Asize, x) - A;
}
void update(int i, int val) {
    for(;i<=Asize;i+=i&-i) {
        BIT[i] += val;
    }
}
int query(int i) {
    int s = 0;
    for(;i>0;i-=i&-i) {
        s += BIT[i];
    }
    return s;
}

int main() {
    int a,b,n,q,T,cas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;++i) {
            scanf("%d %d",&seg[i].a,&seg[i].b);
        }
        for(int i=1;i<=q;++i) scanf("%d",&que[i]);
        arrayCompress(n,q);
        fill(BIT,BIT+Asize+5,0);

        //updates
        for(int i=1;i<=n;++i) {
            a = compressedValue(seg[i].a);
            b = compressedValue(seg[i].b);
            a++, b++;
            update(a, 1);
            update(b+1, -1);
        }

        //queries
        printf("Case %d:\n", ++cas);
        for(int i=1;i<=q;++i) {
            a = compressedValue(que[i]);
            a++;
            int res = query(a);
            printf("%d\n", res);
        }
    }
    return 0;
}

/*
1

5 4

6 12
8 8
10 12
8 11
0 12

11
12
2
20
*/

/*
Given n segments (1 dimensional) and q points, for each point you have to find the number of segments which contain that point. A point pi will lie in a segment A B if A ≤ pi ≤ B.

For example, if the segments are (6 12), (8 8), (10 12), (8 11), (0 12) and the point is 11, then it is contained by 4 segments.

Input:
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case starts with a line containing two integers n (1 ≤ n ≤ 50000) and q (1 ≤ q ≤ 50000).

Each of the next n lines contains two integers Ak Bk (0 ≤ Ak ≤ Bk ≤ 108) denoting a segment.

Each of the next q lines contains an integer denoting a point. Each of them range in [0, 108].

Output:
For each case, print the case number in a single line. Then for each point, print the number of segments that contain that point.
*/