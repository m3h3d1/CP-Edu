#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e3+9;
int comp[N], mu[N];

void sieve() {
	fill(mu, mu+N, 1);
	for(int i=2;i<N;++i) {
		if(!comp[i]) {
			for(int j=i;j<N;j+=i) {
				if(j>i) comp[j] = 1;
				if(j%(i*i)==0) mu[j] = 0;
				mu[j] = -mu[j];
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    sieve();
    for(int i=1;i<100;++i) cout<<mu[i]<<" ";
    return 0;
}