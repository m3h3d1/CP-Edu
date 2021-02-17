#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e6;
const int M = 1e9+7;
int mem[N+9];

int ncr(int n, int r) {
    mem[0]=1;
    for(int i=1;i<=n;++i) {
        for(int j=min(i, r);j;--j) {
            mem[j] = (mem[j] + mem[j-1])%M;;
        }
    }
    return mem[r];
}
int main() {
	ios_base::sync_with_stdio(0);
	int a,b,n,k,T,cas=0;
	cin>>n>>k;
	cout<<ncr(n, k);
	return 0;
}