#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mxn=1e6+5;
bool comp[mxn+7];
vector<int>prime;

void sieve() {
    comp[0] = comp[1] = 1;
    for(ll i=4;i<mxn;i+=2) comp[i] = 1;
    for(ll i=3;i<=mxn/i;i+=2) {
        if(!comp[i]) {
            for(ll j=i*i;j<mxn;j+=i*2) comp[j] = 1;
        }
    }
    prime.push_back(2);
    for(ll i=3;i<mxn;i+=2) if(!comp[i]) prime.push_back(i);
}

inline ll add(ll a, ll b, ll m) {
    //return ((__int128_t)a+b)%m;
    return a < m-b ? a+b : a-(m-b);
}
inline ll mult(ll a, ll b, ll m) { 
    //return ((__int128_t)a*b)%m; //999999999999999989 ei number er jonno overflow kore
    if(b>a) swap(a,b);
    ll res = 0;
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
    while(!(d&1)) {
        s++;
        d>>=1;
    } //n = 2^s * d

    ll a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for(int i=0;i<13 && a[i]<n-1; ++i) {
        ll x = bigmod(a[i], d, n);
        if(x==1 || x==n-1) continue;
        int cmp = 1;
        for(int j=1; j<s; ++j) {
            x = mult(x, x, n);
            if(x==1) return 0;
            else if(x==n-1) {
                cmp = 0;
                break;
            }
        }
        if(cmp) return 0;
    }
    return 1;
}

ll numDiv(ll n) {
    ll res = 1;
    for(int i=0;(ll)prime[i]*prime[i]*prime[i]<=n;++i) {
        int power = 0;
        while(n%prime[i]==0) {
            power++;
            n/=prime[i];
        }
        res *= (power+1);
    }
    ll sq = sqrt(n);
    if(millerRabin(n)) res *= 2;
    else if(millerRabin(sq) && sq*sq==n) res *= 3;
    else if(n!=1) res *= 4;
    return res;
}

int main() {
    sieve();
    ll n;
    scanf("%lld",&n);
    ll res = numDiv(n);
    printf("%lld\n", res);
    return 0;
}

/*
https://vjudge.net/problem/Gym-100753F
12
999999999999999989
100000007700000049
*/

/*
Optimized Solution (O(n^1/3))

1. Split number n in two numbers x and y such that n=x*y where x contains only prime factors in range 2 <= x <= n^(1/3) and y deals with higher prime factors greater than n^(1/3).
2. Count total factors of x using the naive trial division method. Let this count be F(x).
3. Count total factors of y using the following three cases. Let this count be F(y).
    * If y is a prime number then factors will be 1 and y itself. That implies, F(y) = 2.
    * If y is square of a prime number, then factors will be 1, sqrt(y) and y itself. That implies, F(y) = 3.
    * If y is the product of two distinct prime numbers, then factors will be 1, both prime numbers and number y itself. That implies, F(y) = 4.
4. Since F(x*y) is a multiplicative function and gcd(x, y) = 1, that implies, F(x*y) = F(x)*F(y) which gives the count of total distinct divisors of n.

Note that, we have only these three cases for calculating factors of y since there can be at max two prime factors of y. If it would have had more than two prime factors, 
one of them would surely have been less than equal to n^(1/3), and hence it would be included in x and not in y.
*/

//http://codeforces.com/blog/entry/22317
//https://www.geeksforgeeks.org/count-divisors-n-on13/