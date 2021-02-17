#include<iostream>
using namespace std;

int trailingzero(int n) {
	int cnt=0;
	for(int i=5;i<=n;i*=5) {
		cnt+=n/i;
	}
	return cnt;
}
int main() {
	int a,b,n;
	while(cin>>n) {
		cout<<trailingzero(n)<<endl;
	}
	return 0;
}

/*
5
24
25
100
*/