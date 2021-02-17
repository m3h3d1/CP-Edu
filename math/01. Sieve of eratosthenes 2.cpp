#include<iostream>
#include<vector>
using namespace std;

#define mxn 100
bool comp[mxn+5];
vector <int> prime;
void sieve () {
	//fill(comp,comp+n,false);
	comp[0]=comp[1]=1;
	prime.push_back(2);
	for(int i=4;i<=mxn;i+=2) comp[i]=1;
	for(int i=3;i<=mxn;i+=2) {
		if(!comp[i]) prime.push_back(i);
		for(int j=i*i;j<=mxn;j+=i*2) {
			//cout<<j<<" ";
			comp[j]=true;
		}
		//cout<<'\n';
	}
}
int main() {
	int n;
	sieve();
	int sz=prime.size();

	cout<<sz<<endl;
	for(int i=0;i<sz;++i){
		cout<<prime[i]<<" ";
	}
	return 0;
} 