#include<iostream>
using namespace std;

int bigmod(int b,int p,int m) {
	if(b==0) return 0;
	if(p==0) return 1;
	if(p==1) return b%m;
	if(p%2==0) {
		int x=bigmod(b,p/2,m)%m;
		return (x*x)%m;
	}
	else {
		return (b%m*bigmod(b,p-1,m)%m)%m;
	}
}
int main() {
	int b,p,m;
	while(cin>>b>>p>>m) {
		int res=bigmod(b,p,m);
		cout<<res<<endl;
	}
	return 0;
}

/*
3
18132
17

17
1765
3

2374859
3029382
36123

0 0 7
*/