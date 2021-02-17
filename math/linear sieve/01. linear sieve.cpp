#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
const int N = 2e7;
bool comp[N+7];
vector<int> prime;

void linear_sieve() {
	for(int i=2;i<N;++i) {
		if(!comp[i]) prime.push_back(i);
		for(int j=0;i*prime[j]<N;++j) {
			int x = i*prime[j];
			comp[x]=1; // Marking indicates that it is not a prime number 4%2==0 4*2=8
			if(i%prime[j]==0) break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	time_t tim;
	tim = clock();
	linear_sieve();
	tim = clock() - tim;
	cout<<(double)tim/1000<<" sec"<<endl;

	cout<<prime.size()<<endl<<prime[prime.size()-1]<<endl;

	for(int i=0,cnt=1;i<prime.size();++i,++cnt) {
		//cout<<prime[i]<<", ";
		if(cnt==10) {
			//cnt=0; cout<<'\n';
		}
	}
	return 0;
}