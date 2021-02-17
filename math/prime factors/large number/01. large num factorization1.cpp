#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline ll add(ll a, ll b, ll m) {
    return ((__int128_t)a+b)%m;
}
inline ll mult(ll a, ll b, ll m) { 
    return ((__int128_t)a*b)%m;
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
    } //n = 2^s * d

    ll a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for(int i=0;i<13 && a[i]<n-1; ++i) {
        ll x = bigmod(a[i], d, n);
        if(x==1 || x==n-1) continue;
        int comp = 1;
        for(int j=1; j<s; ++j) {
            x = mult(x, x, n);
            if(x==1) return 0; //found a non-trivial sqrt of unity modulo n
            else if(x==n-1) {
                comp = 0;
                break;
            }
        }
        if(comp) return 0; //failed fermat test
    }
    return 1;
}
inline ll f(ll a, ll n, ll c) {
    return add(mult(a, a, n), c, n);
}
ll rho(ll x, ll n) {
    ll y = x, g = 1;
    while(g==1) {
        x = f(x,n,1);
        y = f(y,n,1);
        y = f(y,n,1);
        g = __gcd(x>y ? x-y : y-x, n);
    }
    return g;
}
map<ll, ll> factorize(ll n) {
    ll a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    queue<ll> q;
    map<ll, ll> fact;
    while(!(n&1)) fact[2]++, n/=2;
    q.push(n);
    while(!q.empty()) {
        ll x = q.front();
        q.pop();
        ll r = x;

        if(x==1) break;
        if(millerRabin(x)) {
            fact[x]++;
            continue;
        }
        for(int i=0;i<13 && a[i]<x; ++i) {
            ll y = rho(a[i], x);
            if(y==1 || y==x) continue;
            q.push(y);
            x/=y;
            break;
        }
        if(x!=r) q.push(x); //x could be composite few times
        else {
            //assert(0); //non prime factor
            for(int i=3;i*i<=x;++i) {
                while(x%i==0) {
                    fact[i]++;
                    x/=i;
                }
            }
            if(x>1) fact[x]++;
        }
    }

    return fact;
}
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    ll n;
    cin>>T;
    while(T--) {
        cin>>n;
        map<ll, ll> fact = factorize(n);

        cout<<n<<" =";
        if(n==1) cout<<" "<<n;

        for(auto it=fact.begin(); it!=fact.end(); ++it) {
            if(it!=fact.begin()) cout<<" *";
            cout<<" "<<it->first;
            if(it->second>1) cout<<"^"<<it->second;
        }
        cout<<"\n";
    }
    return 0;
}

/*
3
60
36
10007
*/