#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

void divs(int r) {
	vector<int> v;
	for(int i=1;(long long)i*i<=r;++i) {
		if(r%i==0) {
			v.push_back(i);
			if(i*i!=r) v.push_back(r/i);
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i) printf(" %d",v[i]);
	printf("\n");
}

int main() {
	int a,b,n,cas=0,p,l;
	while(cin>>p) {
		printf("Case %d:",++cas);
		divs(p);
	}
	return 0;
}
/*
1
9
12
123456789
100000000
2520
*/