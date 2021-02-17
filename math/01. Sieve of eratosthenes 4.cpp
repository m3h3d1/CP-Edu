#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
const int mxn=2e7+5;
bool comp[mxn+7] = {1,1};
vector<int>prime;
#define ll long long

void sieve() {
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

int main() {
	time_t tim;
	tim = clock();
	sieve();
	tim = clock() - tim;
	cout<<(double)tim/1000<<" sec"<<endl;
	for(int i=0;i<100;i++) cout<<prime[i]<<" ";
}