#include<iostream>
using namespace std;
const int M = 1e9+7;
const int base = 131;
#define ll long long
int pref[10000];

int bigmod(int b, int p,int m) {
	if(p==0) return 1;
	int x=bigmod(b,p/2,m);
	if(p%2==0) return ((ll)x*x)%m;
	else return (((ll)x*x)%m*b)%m;
}
int Mod(long long a) {  /// *** long long
	return (a%M + M)%M;
}
int match(string &str, string &pattern) {
	int l1=str.size();
	int l2=pattern.size();
	int hp = 0;
	for(int i=0;i<l2;++i) {
		int temp=Mod((ll)pattern[i]*bigmod(base,i,M));
		hp=Mod(hp+temp);
	}
	int ht;
	for(int i=1;i<=l1-l2+1;++i) {
		ht=Mod(pref[i+l2-1]-pref[i-1]);
		int a=bigmod(base,i-1,M);
		int b=bigmod(a,M-2,M);
		ht=Mod(((ll)ht*b)%M);
		//printf("%d %d => %d %d %d %d\n",pref[i+l2-1],pref[i-1],a,b,ht,hp);
		if(ht==hp) return 1;
	}
	return 0;
}
int main() {
	int a,b,n,q;
	string str, pattern;
	cin>>str;
	pref[0]=0;
	for(int i=0;str[i];++i) {
		pref[i+1]=Mod((ll)pref[i]+Mod((ll)str[i]*bigmod(base,i,M)));
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