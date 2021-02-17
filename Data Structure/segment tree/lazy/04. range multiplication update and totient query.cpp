#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int mod = 1e9+7;

ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

const int mxn=300;
bool comp[mxn+9]={1,1};
vector<ll> prime, invPrime;
void sieve() {
    for(int i=2;i<=mxn;++i) {
        if(!comp[i]) {
            prime.push_back(i);
            invPrime.push_back(powmod(i, mod-2));
        }
        for(int j=0;i*prime[j]<=mxn;++j) {
            comp[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

ll getMask(ll x) {
    ll mask=0;
    for(int i=0;i<prime.size();++i) {
        if(x%prime[i]==0) 
            mask |= (1ll<<i);
    }
    return mask;
}

#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int N = 4e5+9;
struct node {
    ll prod, msk;
    ll lazyProd, lazyMsk;
    node operator + (const node &a) const {
        node c;
        c.prod = prod * a.prod % mod;
        c.msk = msk | a.msk;
        return c;
    }
} st[N*4];
ll A[N];

void pushup(int v) {
    st[v].prod = st[v*2].prod * st[v*2+1].prod % mod;
    st[v].msk = st[v*2].msk | st[v*2+1].msk;
}
void build(int v, int l, int r) {
    st[v].lazyProd = 1;
    st[v].lazyMsk = 0;
    if(l==r) {
        st[v].prod = A[l];
        st[v].msk = getMask(A[l]);
        return;
    }
    int m = (l+r)/2;
    build(lchild);
    build(rchild);
    pushup(v);
}
void change(int v, int l, int r, ll lazyProd, ll lazyMsk) {
    st[v].prod = st[v].prod * powmod(lazyProd, r-l+1) % mod;
    st[v].msk |= lazyMsk;
    if(l!=r) {
        st[v].lazyProd = st[v].lazyProd * lazyProd % mod;
        st[v].lazyMsk |= lazyMsk;
    }
}
void pushdown(int v, int l, int r) {
    int m = (l+r)/2;
    change(lchild, st[v].lazyProd, st[v].lazyMsk);
    change(rchild, st[v].lazyProd, st[v].lazyMsk);
    st[v].lazyProd=1;
    st[v].lazyMsk=0;
}
void update(int v, int l, int r, int i, int j, ll x) {
    if(l>=i && r<=j) {
        change(v, l, r, x, getMask(x));
        return;
    }
    if(st[v].lazyProd!=1 || st[v].lazyMsk) pushdown(v, l, r);
    int m = (l+r)/2;
    if(j<=m) update(lchild, i, j, x);
    else if(i>m) update(rchild, i, j, x);
    else {
        update(lchild, i, m, x);
        update(rchild, m+1, j, x);
    }
    pushup(v);
}
node query(int v, int l, int r, int i, int j) {
    if(l>=i && r<=j) return st[v];
    if(st[v].lazyProd!=1 || st[v].lazyMsk) pushdown(v, l, r);
    int m = (l+r)/2;
    if(j<=m) return query(lchild, i, j);
    else if(i>m) return query(rchild, i, j);
    else {
        node a = query(lchild, i, m);
        node b = query(rchild, m+1, j);
        return a+b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    sieve();
    int a,b,n,q;
    string typ;
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>A[i];
    build(1,1,n);

    while(q--) {
        cin>>typ>>a>>b;
        if(typ=="MULTIPLY") {
            ll x; cin>>x;
            update(1,1,n,a,b,x);
        }
        else {
            node p = query(1,1,n,a,b);
            ll phi=p.prod;
            for(int i=0;i<prime.size();++i) {
                if(p.msk & (1ll<<i))
                    phi = (((phi * (prime[i]-1))%mod) * invPrime[i])%mod;
            }
            cout<<phi<<endl;
        }
    }
    return 0;
}

// https://codeforces.com/contest/1114/problem/F
// bit minipulation + segment tree + totient
// https://vjudge.net/problem/CodeForces-1114F