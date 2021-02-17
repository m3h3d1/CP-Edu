#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline ll add(ll a, ll b, ll m) {
    return (__int128_t)a+b%m;
}
inline ll mult(ll a, ll b, ll m) {
    return (__int128_t)a*b%m;
}
ll bigmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1%m;
    while(b) {
        if(b&1) res = mult(res, a, m);
        a = mult(a, a, m);
        b>>=1;
    }
    return res;
}
int millerRabin(ll n) {
    if(n<2 || (n!=2 && !(n&1))) return 0;
    int s = 0;
    ll d = n-1;
    while(!(d&1)) {
        s++;
        d>>=1;
    }

    ll a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for(int i=0;i<13 && a[i]<n-1; ++i) {
        ll x = bigmod(a[i], d, n);
        if(x==1 || x==n-1) continue;
        int cmp = 1;
        for(int j=1;j<s;++j) {
            x = mult(x, x, n);
            if(x==1) return 0; //found a non-trivial sqrt of unity modulo n
            else if(x==n-1) {
                cmp = 0;
                break;
            }
        }
        if(cmp) return 0; //failed fermat test
    }
    return 1;
}
inline ll f(ll a, ll c, ll n) {
    return add(mult(a, a, n), c, n);
}
ll rho(ll x, ll n) {
    ll y = x, d = 1;
    while(d==1) {
        x = f(x, 1, n);
        y = f(y, 1, n);
        y = f(y, 1, n);
        d = __gcd(abs(x-y), n);
    }
    return d;
}

map<ll, int> fact;
void factorize(ll n) {
    if(n==1) return;
    if(millerRabin(n)) {
        fact[n]++;
        return;
    }

    ll a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    ll d = n;
    for(int i=0;i<13 && a[i]<n-1 && d==n;++i) {
        d = rho(a[i], n);
    }
    if(d==n) {
        while(n%2==0) fact[2]++, n/=2;
        for(int i=3;i*i<=n;i+=2) {
            while(n%i==0) {
                fact[i]++;
                n/=i;
            }
        }
        if(n>1) fact[n]++;
    }
    else {
        factorize(d);
        factorize(n/d);
    }
}
int main() {
    int T;
    ll n;
    scanf("%d",&T);
    while(T--) {
        fact.clear();
        scanf("%lld",&n);
        factorize(n);

        printf("%lld =", n);
        if(n==1) printf(" %lld", n);
        int fst = 1;
        for(auto x : fact) {
            if(!fst) printf(" *");
            else fst = 0;
            printf(" %lld", x.first);
            if(x.second>1) printf("^%d", x.second);
        }
        printf("\n");
    }
    return 0;
}

/*
uva 11476 (1440 ms)
3
60
36
10007
*/