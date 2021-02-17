#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e3+9;
int mu[N];

void mobius() {
	mu[1] = 1;
	for(int i=1;i<N;++i) {
		for(int j=2*i;j<N;j+=i) 
			mu[j] -= mu[i];
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    mobius();
    for(int i=1;i<100;++i) cout<<mu[i]<<" ";
    return 0;
}