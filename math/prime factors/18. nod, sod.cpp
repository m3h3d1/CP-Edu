#include<iostream>
#include<vector>
using namespace std;
const int mxn=2e7+5;
bool comp[mxn+7];
vector<int>prime;
#define ll long long
ll nod, sod;

void sieve() {
	comp[0]=comp[1]=1;
	for(ll i=4;i<mxn;i+=2) comp[i]=1;
	for(ll i=3;i<=mxn/i;i+=2) {
		if(!comp[i]) {
			for(ll j=i*i;j<mxn;j+=2*i) comp[j]=1;
		}
	}
	for(ll i=1;i<mxn;++i) {
		if(!comp[i]) prime.push_back(i);
	}
}

void solve(ll n) {
	nod = sod = 1;
	ll s, p, cnt;
	for(int i=0;prime[i]*prime[i]<=n;++i) {
		cnt = 0; //counts power
		if(n%prime[i]==0) {
			s = p = prime[i];
			while(n%prime[i]==0) {
				n/=prime[i];
				++cnt;
				s*=prime[i];
			}
			nod*=(cnt+1);
			sod*=(s-1)/(p-1);
		}
	}
	if(n!=1) {
		nod *= 2;
		sod *= (n+1);
	}
}

int main() {
	sieve();
	int n;
	while(cin>>n) {
		solve(n);
		cout<<nod<<" "<<sod<<endl;
	}
	return 0;
}

/*
2
6
100
999999
*/