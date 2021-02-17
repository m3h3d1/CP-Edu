#include<iostream>
#include<vector>
using namespace std;
#define N 101
bool comp[N];
vector<int> prime;
int pf[N];

void sieve() {
	for(int i=2;i<N;++i) {
		if(!comp[i]) {
			prime.push_back(i);
			pf[i]=1;
		}
		for(int j=0;i*prime[j]<N;++j) {
			comp[i*prime[j]]=true;
			pf[i*prime[j]]=pf[i]+1;
			if(i%prime[j]==0) {
				break;
			}
		}
	}
}

int main() {
	sieve();
	for(int i=0;i<N;++i) cout<<i<<": "<<pf[i]<<'\n';
	return 0;
}