#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define ll long long

// return ((__int128_t)a+b) % m;
inline ll add(ll a, ll b, ll m) {
    return a<m-b ? a+b : a-(m-b);
}

//return ((__int128_t)a*b) % m;
ll mult(ll a, ll b, ll m) {
    ll res = 0;
    if(b>a) swap(a,b);
    while(b) {
        if(b&1) res = add(res, a, m);
        a = add(a, a, m);
        b>>=1;
    }
    return res;
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
    while((d&1)==0) {
        s++;
        d>>=1;
    } // n = 2^s * d

    vector<ll> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for(int i=0;i<v.size() && v[i]<n-1;++i) {
        ll x = bigmod(v[i], d, n); // x = a^d % n
        if(x==1 || x==n-1) continue;

        int compo = 1;
        for(int j=1;j<s;++j) {
            x = mult(x, x, n); // x = x^2 % n
            if(x==1) return 0; // Found a non-trivial sqrt of unity modulo n
            else if(x==n-1) { // could be a strong liar. try another a
                compo = 0;
                break;
            }
        }
        if(compo) return 0; // Failed fermat test
    }
    return 1;
}

int main() {
    ll n;
    while(~scanf("%I64d",&n)) {
        if(millerRabin(n)) printf("It is a prime number.\n");
        else printf("It is not a prime number.\n");
    }
    return 0;
}