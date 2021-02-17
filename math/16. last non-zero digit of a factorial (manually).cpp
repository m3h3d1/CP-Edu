#include<iostream>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;

string stringmul(string &s1,string &s2) {
	int l1=s1.size(),l2=s2.size();
	vector<int> s(l1+l2,0);
	for(int i=l2-1;i>=0;--i) {
		for(int j=l1-1;j>=0;--j) {
			s[i+j+1]+=(s2[i]-'0')*(s1[j]-'0');
		}
	}
	for(int i=l1+l2-1;i>=0;--i) {
		int tmp=s[i]/10;
		s[i]%=10;
		s[i-1]+=tmp;
	}
	int i=0; string res="";
	while(s[i]==0) ++i;
	for(;i<l1+l2;++i) res+=s[i]+'0';
	return res;
}

const int mxn=1e4+5;
vector<string> fact;
void pre() {
	string s="1";
	fact.push_back(s);
	for(int i=1;i<=mxn;++i) {
		stringstream ss;
		ss<<i;
		string s1;
		ss>>s1;
		s=stringmul(s,s1);
		fact.push_back(s);
	}
}
int trailingzero(int n) {
	int cnt=0;
	for(int i=5;i<=n;i*=5) {
		cnt+=n/i;
	}
	return cnt;
}
int main() {
	pre();
	int a,b,n;
	while(cin>>n) {
		int x=trailingzero(n);
		cout<<setw(5)<<n<<" -> "<<fact[n][fact[n].size()-x-1]<<endl;
	}
	return 0;
}

/*
uva 568

1
2
26
125
3125
9999
*/