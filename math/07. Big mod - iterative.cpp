#include<iostream>
using namespace std;
#define ll long long
using u128 = __uint128_t;

ll bigmod(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while(b) {
        if(b&1)
            res = (u128) res * a % m;
        a = (u128)a * a % m;
        b>>=1;
    }
    return res;
}
int main() {
	int a,b,n;
	cout<<bigmod(3,4,10)<<endl;
	return 0;
}