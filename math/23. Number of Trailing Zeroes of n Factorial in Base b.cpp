#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;

ll calc(ll n, ll a) {
    ll cnt=0;
    while(n) {
        cnt+=n/a;
        n/=a;
    }
    return cnt;
}
template <class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i)
      while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    ll n, b;
    cin>>n>>b;
    map<ll, int> mp = factorize(b);
    ll zero = 1e18;
    for(auto p: mp) {
        ll x = calc(n, p.first)/p.second;
        zero = min(zero, x);
    }
    cout<<zero<<endl;
    return 0;
}

/*
https://codeforces.com/contest/1114/problem/C
https://www.youtube.com/watch?v=713aMqMIfDQ
https://forthright48.com/number-of-trailing-zeroes-of-factorial/
*/