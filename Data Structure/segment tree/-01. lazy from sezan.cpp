#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
ll tree[4*N], lazy[4*N];

void change(int v, int s, int e, ll val) {
    tree[v] += val;
    lazy[v] += val;
}
void push(int v, int s, int e) {
    int m = (s+e)/2;
    change(2*v, s, m, lazy[v]);
    change(2*v+1, m+1, e, lazy[v]);
    lazy[v] = 0;
}
void update(int v, int s, int e, int l, int r, int val) {
    if(l>e && r<s) return;
    if(s>=l && e<=r) {
        change(v, s, e, val);
        return;
    }
    push(v, s, e);
    int m = (s+e)/2;
    update(2*v, s, m, l, r, val);
    update(2*v+1, m+1, e, l, r, val);
    tree[v] = max(tree[2*v], tree[2*v+1]);
}
ll query(int v, int s, int e, int l, int r) {
    if(l>e || r<s) return -1e18;
    if(s>=l && e<=r) return tree[v];
    push(v, s, e);
    int m = (s+e)/2;
    return max(query(2*v, s, m, l, r), query(2*v+1, m+1, e, l, r));
}
int main() {
    int a,b,n,T,cas=0;
    
    return 0;
}