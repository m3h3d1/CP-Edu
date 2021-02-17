#include<iostream>
#include<vector>
using namespace std;
#define ll long long

const int mxn=1e5+10;
bool comp[mxn];
vector<ll> prime;
void sieve() {
	for(ll i=2;i<mxn;++i) {
		if(!comp[i]) prime.push_back(i);
		for(ll j=0;i*prime[j]<mxn;++j) {
			comp[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
ll bigmod(ll a,ll b,ll m) {
	if(b==0) return 1;
	ll x=bigmod(a,b/2,m)%m;
	if(b%2==0) {
		return (x*x)%m;
	}
	ll y=(x*x)%m;
	return (a%m * y)%m;
}
const ll mod=1e9+7;
ll sod(ll n,ll m) {
	ll s=1,i=0;
	while(prime[i]*prime[i]<=n) {
		if(n%prime[i]==0) {
			ll cnt=0;
			while(n%prime[i]==0) {
				n/=prime[i];
				cnt++;
			}
			ll lob=bigmod(prime[i],m*cnt+1,mod)-1;
			ll hor=bigmod(prime[i]-1,mod-2,mod);
			ll x=(lob%mod*hor%mod)%mod;
			s=(s*x)%mod;
		}
		i++;
	}
	if(n!=1) {
		ll x;
		if(n%mod==0){
			x=1;
		}
		else{
			ll lob=bigmod(n,m+1,mod)-1;
			ll hor=bigmod(n-1,mod-2,mod);
			x=(lob%mod*hor%mod)%mod;
		}
		s=(s*x)%mod;
	}
	return s;
}
int main() {
	sieve();
	ll n,m,T,cas=0,x;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		x=sod(n,m);
		printf("Case %lld: ",++cas);
		cout<<x<<'\n';
	}
	return 0;
}

/*
lightoj 1054 - Efficient Pseudo Code

pseudo code
{
    take two integers n and m
    let p = n ^ m (n to the power m)
    let sum = summation of all the divisors of p
    let result = sum MODULO 1000,000,007
}

Now given n and m you have to find the desired result from the pseudo code. For example if n = 12 and m = 2. Then if we follow the pseudo code, we get
pseudo code
{
    take two integers n and m
    so, n = 12 and m = 2
    let p = n ^ m (n to the power m)
    so, p = 144
    let sum = summation of all the divisors of p
    so, sum = 403, since the divisors of p are 1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 36, 48, 72, 144
    let result = sum MODULO 1000,000,007
    so, result = 403
}

Input
Input starts with an integer T (≤ 5000), denoting the number of test cases.
Each test case will contain two integers, n (1 ≤ n) and m (0 ≤ m). Each of n and m will be fit into a 32 bit signed integer.

Output
For each case of input you have to print the case number and the result according to the pseudo code.
*/
/*
5
1000000000 1000000000
1000000007 10
*/