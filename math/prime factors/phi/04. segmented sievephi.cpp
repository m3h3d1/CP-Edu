#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e7+5;
bool comp[N+7]={1,1};
vector<int>prime;
#define ll long long
ll segPhi[100005], num[100005];

void sieve() {
    for(int i=3;i<=N/i;i+=2) {
        if(!comp[i]) {
            for(int j=i*i;j<N;j+=2*i) comp[j]=1;
        }
    }
    prime.emplace_back(2);
    for(int i=3;i<N;i+=2) {
        if(!comp[i]) prime.emplace_back(i);
    }
}
void segSievePhi(ll a, ll b) {
	for(ll i=a;i<=b;++i) num[i-a] = segPhi[i-a] = i;
	for(int i=0;i<prime.size() && (ll) prime[i]*prime[i]<=b;++i) {
		ll p = prime[i];
		ll j = p*p;
		if(j<a) j = ((a+p-1)/p) * p; // j = ceil(a/p)*p
		for(;j<=b;j+=p) {
			while(num[j-a]%p==0) num[j-a]/=p;
			segPhi[j-a] -= segPhi[j-a]/p;
		}
	}
	for(ll i=a;i<=b;++i) {
		if(num[i-a]!=1) segPhi[i-a] -= segPhi[i-a]/num[i-a];
		cout<<segPhi[i-a]<<'\n';
	}
}

int main(){
	sieve();
	ios_base::sync_with_stdio(false);
	int n,T,cas=0;
	ll a, b;
	cin>>a>>b;
	segSievePhi(a, b);
	return 0;
}

/*
SPOJ: ETFS - Euler Totient Function Sieve
1 5
*/