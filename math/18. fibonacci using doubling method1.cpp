#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int mxn = 1e5;
ll m, arr[mxn];

ll fib(ll n) {
	if(n==0) return 0;
	else if(n<=2) return 1;
	if(n<mxn && arr[n]) return arr[n];
	ll x = n / 2;
	ll a = fib(x);
	ll b = fib(x+1);
	if(x<mxn) arr[x] = a;
	if(x+1<mxn) arr[x+1] = b;
	if(n%2 == 0) {
		ll res = (a * ((2ll*b)%m - a)%m)%m;
		if(n<mxn) arr[n] = res;
		return res;
	}
	else {
		ll res = ((a*a)%m + (b*b)%m)%m;
		if(n<mxn) arr[n] = res;
		return res;
	}
}
int main() {
	ll n;
	while(scanf("%lld %lld",&n,&m) != EOF){
		memset(arr,0,sizeof(arr));
		m = 1<<m;
		ll res = fib(n);
		if(res<0) printf("%lld\n", res+m);
		else printf("%lld\n", res);
	}
	return 0;
}

/*
11 7
11 6
1028291842 16
609007406 10
*/