#include<iostream>
using namespace std;

#define ll long long
ll csod(int n) {
	if(n==0) return 0; //*
	ll s=(ll)-n*(n+1)/2; //*
	for(int i=1;(ll)i*i<=n;++i) {
		int j=n/i;
		s+=(ll) (i+j)*(j-i+1)/2;
		s+=(ll) i*(j-i);
	}
	s-=n-1; //*
	return s;
}
int main() {
	int a,b,n,T,cas=0;
	cin>>T;
	while(T--) {
		cin>>n;
		ll res=csod(n);
		printf("Case %d: %lld\n",++cas,res);
	}
	return 0;
}

/*
3

2
100
200000000
*/

/*
We all know that any integer number n is divisible by 1 and n. 
That is why these two numbers are not the actual divisors of any numbers. 
The function SOD(n) (sum of divisors) is defined as the summation of all the 
actual divisors of an integer number n. For example,

SOD(24) = 2+3+4+6+8+12 = 35.

Each case contains an integer n (0 ≤ n ≤ 2 * 10^9).
*/