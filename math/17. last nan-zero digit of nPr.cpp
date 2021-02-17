#include<iostream>
using namespace std;
#define ll long long
const int mod=1e9;

ll lastnonzero(int n,int r) {
	ll tmp=1;
	for(int i=n;i>=(n-r)+1;--i) { //samne theke gun kore gele overflow khay
		tmp*=i;
		while(tmp%10==0) tmp/=10;
		tmp%=mod;
	}
	return tmp%10;
}
int main() {
	int a,b,n,r;
	while(cin>>n>>r) {
		ll res=lastnonzero(n,r);
		cout<<res<<endl;
	}
	return 0;
}

/*
uva 10212:
 Each line of the input file contains two integers N
(0 ≤ N ≤ 20000000), M (0 ≤ M ≤ N). 
*/