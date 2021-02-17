#include<iostream>
#include<vector>
using namespace std;
#define mxn 101
bool iscomp[mxn];
vector<int> prime;
int sdiv[mxn];

void sieve() {
	for(int i=2;i<mxn;++i) {
		if(!iscomp[i]) {
			prime.push_back(i);
			sdiv[i]=i;
		}
		for(int j=0;i*prime[j]<mxn;++j) {
			iscomp[i*prime[j]]=true;
			sdiv[i*prime[j]]=prime[j];
			if(i%prime[j]==0) {
				break;
			}
		}
	}
	sdiv[1]=1;
}

int main() {
	sieve();
	for(int i=0;i<mxn;++i) cout<<i<<": "<<sdiv[i]<<'\n';
	return 0;
}