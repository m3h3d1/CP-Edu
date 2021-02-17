#include<iostream>
#include<vector>
using namespace std;
#define ll long long

const int mxn=5e7+5;
bool comp[mxn];
vector<int> prime;
void sieve() {
	for(int i=2;i<mxn;++i) {
		if(!comp[i]) prime.push_back(i);
		for(int j=0;i*prime[j]<mxn;++i) {
			comp[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}

ll pfact(long long n) {
	ll mx=-1,cnt=0;
	for(int i=0;(long long)prime[i]*prime[i]<=n;++i) {
		if(n%prime[i]==0) {
			//cnt++;
			if(prime[i]>mx) mx=prime[i];
			while(n%prime[i]==0) {
				n/=prime[i];
			}
		}
	}
	if(n!=1) {
		if(n>mx) mx=n;
		//cnt++;
	}
	//if(cnt<2) return -1;
	return mx;
}
int main() {
	sieve();
	ll n;
	while(scanf("%lld",&n) && n) {
		if(n<0) n*=-1;
		ll mx=pfact(n);
		printf("%lld\n",mx);
	}
	return 0;
}

/*
2
6
100
34
-18
0
*/

/*
The input file contains at most 450 sets of inputs. Each line contains a decimal integer N. N does
not have more than 14 digits.
*/