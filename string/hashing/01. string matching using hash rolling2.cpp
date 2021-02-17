#include<iostream>
using namespace std;
const int M = 1e9+7;
const int base = 131;
const int mxn = 1e6+5;
#define ll long long
int pref[mxn];

int power[mxn];
void pre() {
	power[0]=1;
	for(int i=1;i<mxn;++i) {
		power[i]=((ll)power[i-1]*base)%M;
	}
}
int Mod(long long a) {  /// *** long long
	return (a%M + M)%M;
}
int match(string &str, string &pattern) {
	int l1=str.size();
	int l2=pattern.size();
	int hp = 0;
	for(int i=0;i<l2;++i) {
		int temp=((ll)pattern[i]*power[i])%M;
		hp=((ll)hp+temp)%M;
	}
	int ht,check=0;
	for(int i=1;i<=l1-l2+1;++i) {
		ht=Mod(pref[i+l2-1]-pref[i-1]);
		int x=((ll)hp*power[i-1])%M;
		
		if(ht==x) return 1;
	}
	return 0;
}
int main() {
	pre();
	int a,b,n,q;
	string str, pattern;
	cin>>str;
	pref[0]=0;
	for(int i=0;str[i];++i) {
		pref[i+1]=Mod((ll)pref[i]+Mod((ll)str[i]*power[i]));
	}
	cin>>q;
	while(q--) {
		cin>>pattern;
		if(match(str,pattern)) cout<<"  Yes\n";
		else cout<<"  no\n";
	}
	return 0;
}

/*
abcdefghijklmnopqrstuvwxyz
15

a
y
z
abc
xyz
mnop
abcdefghijklmnopqrstuvwxyz
def
pqrst
fghijkl
wxyz

aaaaaa
gfhgc
abcdeff
abcdefghijklmnopqrstuvwxyy
ijhg
*/