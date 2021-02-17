#include<iostream>
using namespace std;
#define ll long long
const int mod=1e6+3;
const int mxn=1e6+1;

ll fact[mxn];
void pre() { //pre calculated mod value
	fact[0]=1;
	for(int i=1;i<mxn;++i) {
		fact[i]=(fact[i-1]*i)%mod;
	}
}
ll bigmod(ll a,ll b,ll m) {
	if(a==0) return 0;
	if(b==0) return 1;
	ll x=bigmod(a,b/2,m);
	if(b%2==0) return (x%m * x%m)%m;
	return (x%m * x%m * a%m)%m;
}
ll ncr(int n,int r) {
	ll lob=fact[n];
	ll hor=bigmod((fact[r]*fact[n-r])%mod,mod-2,mod);
	ll res=(lob%mod * hor%mod)%mod;
	return res;
}
int main() {
	pre();
	int a,b,n,cas=0,T,r;
	cin>>T;
	while(T--) {
		cin>>n>>r;
		ll res=ncr(n,r);
		printf("Case %d: %lld\n",++cas,res);
	}
	return 0;
}