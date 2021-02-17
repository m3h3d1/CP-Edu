#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e5+5;
bool comp[N+7]={1,1};
vector<int>prime;
#define ll long long
bool seg[100005];

void sieve() {
    for(int i=3;i<=N/i;i+=2) {
        if(!comp[i]) {
            for(int j=(ll)i*i;j<N;j+=2*i) comp[j]=1;
        }
    }
    prime.emplace_back(2);
    for(int i=3;i<N;i+=2) {
        if(!comp[i]) prime.emplace_back(i);
    }
}
void segSieve(ll a, ll b) {
	fill(seg, seg+b-a+1, 0);
	if(a==1) seg[0]=1;
	for(int i=0;1ll*prime[i]*prime[i]<=b;++i) {
		int p = prime[i];
		ll j = p*p; // p*p er ager gula sieve func a generate kora hoiche
		if(j<a) j = ((a+p-1)/p) * p; // j = ceil(a/p)*p
		for(;j<=b;j+=p) {
			seg[j-a] = 1; // composite
		}
	}
	for(ll i=a;i<=b;++i) {
		if(!seg[i-a]) cout<<i<<" ";
	}
	cout<<'\n';
}

int main(){
	sieve();
	ios_base::sync_with_stdio(false);
	int n,T,cas=0;
	ll a, b;
	while(cin>>a>>b) {
		segSieve(a, b);
	}
	return 0;
}