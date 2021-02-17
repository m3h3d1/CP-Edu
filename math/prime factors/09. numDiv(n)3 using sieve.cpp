#include<iostream>
using namespace std;

const int mxn=1e3+1;
int divs[mxn];
void sieve() {
	for(int i=1;i<mxn;++i) {
		for(int j=i;j<mxn;j+=i) {
			divs[j]++;
		}
	}
}

int main() {
	sieve();
	for(int i=1;i<mxn;++i) {
		cout<<i<<" "<<divs[i]<<endl;
	}
	int a,b,n;
	return 0;
}