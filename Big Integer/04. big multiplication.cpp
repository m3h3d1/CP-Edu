#include<iostream>
#include<vector>
using namespace std;

string bigmul(string &s1,string &s2) {
	int l1=s1.size(), l2=s2.size();
	vector<int> a(l1),b(l2),s(l1+l2,0);
	for(int i=l1-1,j=0;i>=0;i--,j++) a[j]=s1[i]-'0';
	for(int i=l2-1,j=0;i>=0;i--,j++) b[j]=s2[i]-'0';
	for(int i=0;i<l2;++i) {
		for(int j=0;j<l1;++j) {
			s[i+j]+=b[i]*a[j];
		}
	}
	for(int i=0;i<l1+l2;++i) {
		int tmp=s[i]/10;
		s[i]%=10;
		s[i+1]+=tmp;
	}
	int i;
	for(i=l1+l2-1;i>=0;--i) {
		if(s[i]>0) break;
	}
	string res="";
	while(i>=0) res+=s[i--]+'0';
	if(res=="") res="0";
	return res;
}
int main() {
	int a,b,n;
	string s1,s2;
	while(cin>>s1>>s2) {
		string res=bigmul(s1,s2);
		cout<<res<<endl;
	}
	return 0;
}

/*
123 456
000 000
*/