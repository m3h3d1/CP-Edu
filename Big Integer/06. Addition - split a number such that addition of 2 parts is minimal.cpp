#include<bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
	if(s1.size() < s2.size()) swap(s1, s2); //length of s1>s2
	string res="";
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int carry = 0;
	for(int i=0; i<s2.size(); ++i) {
		int x = (s1[i]-'0') + (s2[i]-'0') + carry;
		res.push_back(x%10 + '0');
		carry = x/10;
	}
	for(int i=s2.size(); i<s1.size(); ++i) {
		int x = (s1[i]-'0') + carry;
		res.push_back(x%10 + '0');
		carry = x/10;
	}
	if(carry) res.push_back(carry+'0');
	reverse(res.begin(), res.end());
	//cout<<res<<endl;
	return res;
}
int minn(string a, string b) {
	if(a.size() != b.size()) return a.size() < b.size();
	for(int i=0;i<a.size();++i) {
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return 0;
}
int main() {
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	int m = n/2;
	int cnt = 3;
	string res = s;
	for(int i=m;i<=n && cnt;++i) {
		if(s[i]=='0') continue;
		string cur = add(s.substr(0,i), s.substr(i,s.size()));
		//cout<<s.substr(0,i)<<" "<<s.substr(i,s.size())<<endl;
		if(minn(cur, res)) res = cur;
		--cnt;
	}
	cnt = 3;
	for(int i=m;i>=0 && cnt;--i) {
		if(s[i]=='0') continue;
		string cur = add(s.substr(0, i), s.substr(i, s.size()));
		//cout<<s.substr(0,i)<<" "<<s.substr(i, s.size())<<endl;
		if(minn(cur, res)) res = cur;
		--cnt;
	}
	cout<<res;
	return 0;
}

/*
split a number into 2 part such that addition of 2 parts is minimal
*/

/*
10
1100000000

20
67378957561978988538

7
1234567
*/