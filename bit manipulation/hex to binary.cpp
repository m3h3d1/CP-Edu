#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e6;

int main() {
	ios_base::sync_with_stdio(0);
	int a,b,n,T,cas=0;
	string s;
	cin>>s;
	s="0x"+s;

	stringstream ss;
	ss<<hex<<s;
	ss>>n;
	
	bitset<32> bit(n);
	string str=bit.to_string();
	cout<<str<<endl;
	return 0;
}