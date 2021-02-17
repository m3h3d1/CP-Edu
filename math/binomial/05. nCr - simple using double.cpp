#include<iostream>
using namespace std;
#define ll long long

ll ncr(int n, int r) {
	r = min(r, n-r);
	double res=1;
	for(int i=1;i<=r;++i) res=res*(n-r+i)/i;
	return (ll)(res+0.01);
}
int main(){
	ios_base::sync_with_stdio(false);
	int a,b,n,k,T,cas=0;
	while(cin>>n>>k && (n||k)) {
		ll res = ncr(n, k);
		cout<<res<<endl;
	}
	return 0;
}