#include<iostream>
using namespace std;
#define ll long long
ll m, f[2];

// Set f[0], f[1] to F(n), F(n+1).
void fibo(ll n) {
	if(!n) {
		f[0] = 0;
		f[1] = 1;
		return;
	}
	fibo(n/2);	 // k = floor(n/2), so k = n / 2 if n is even, k = (n-1) / 2 if n is odd.
	ll a = f[0]; // F(k)
	ll b = f[1]; // F(k+1)

	ll c = (a * ((2ll*b)%m - a)%m)%m; // F(2k) = F(k) * [ 2 * F(k+1) – F(k) ]
	ll d = ((a * a)%m + (b * b)%m)%m; // F(2k+1) = F(k+1)^2 + F(k)^2

	if(n % 2 == 0) {	// k = n / 2, so F(2k) = F(n), F(2k+1) = F(n+1).
		f[0] = c; 		// F(n) = F(2k)
		f[1] = d;		// F(n + 1) = F(2k + 1)
	} else { 			// k = (n - 1) / 2, so F(2k) = F(n-1), F(2k+1) = F(n).
		f[0] = d; 		// F(n) = F(2k+1)
		f[1] = (c+d)%m; // F(n+1) = F(n-1) + F(n) = F(2k) + F(2k+1).
	}
}
int main() {
	ll n;
	while(cin>>n>>m) {
		m = 1<<m;
		fibo(n);
		ll res = f[0];
		if(res<0) res+=m;
		cout<<res<<'\n';
	}
	return 0;
}

//https://chunminchang.github.io/blog/post/calculating-fibonacci-numbers-by-fast-doubling
/*
11 7
11 6
1028291842 16
609007406 10
*/

/*
Write a program which calculates Mn = Fn mod 2^m for given pair of n and m. 0 ≤ n ≤ 2147483647
and 0 ≤ m < 20. Note that a mod b gives the remainder when a is divided by b.
*/