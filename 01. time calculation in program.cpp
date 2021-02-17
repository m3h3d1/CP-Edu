#include<iostream>
#include<ctime>
using namespace std;
const int mxn=1e9;

int main() {
	clock_t t;
	t=clock();
	for(int i=0;i<mxn;++i);
	t=clock()-t;
	cout<<(double)t/CLOCKS_PER_SEC<<" sec"<<endl;
	return 0;
}

// on Windows CLOCKS_PER_SEC is 1000 and on Mac OS X, Linux it is 1000000