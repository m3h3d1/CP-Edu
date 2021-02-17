#include<iostream>
#include<vector>
using namespace std;
#define N 101
bool comp[N];
vector<int> prime;
int phi[N];

void sieve() {
	for(int i=2;i<N;++i) {
		if(!comp[i]) { //1. i is prime
			prime.push_back(i);
			phi[i]=i-1;
		}
		for(int j=0;i*prime[j]<N;++j) {
			int x = i*prime[j];
			comp[x]=1;
			if(i%prime[j]==0) { //3. prime[j] divides i
				phi[x]=phi[i]*prime[j];
				break;
			}
			else phi[x]=phi[i]*phi[prime[j]]; //2. prime[j] doesn't devide i (co-prime)
		}
	}
	phi[1]=1;
}
int main() {
	sieve();
	for(int i=0;i<N;++i) cout<<i<<": "<<phi[i]<<'\n';
	return 0;
}