#include<iostream>
#include<vector>
using namespace std;

string stringmul(string &s1,string &s2) {
	int l1=s1.size(), l2=s2.size();
	vector<int> s(l1+l2,0);
	for(int i=l2-1;i>=0;--i) {
		for(int j=l1-1;j>=0;--j) {
			s[i+j+1]+=(s2[i]-'0')*(s1[j]-'0');
		}
	}
	for(int i=l1+l2-1;i>=0;--i) {
		int tmp=s[i]/10;
		s[i]%=10;
		if(i!=0) s[i-1]+=tmp; // error
	}
	int i=0; string res="";
	while(i<l1+l2 && s[i]==0) i++;
	for(;i<l1+l2;++i) {
		res+=s[i]+'0';
	}
	
	if(res=="") res="0";
	return res;
}
int main() {
	int a,b,n;
	string s1,s2;
	while(cin>>s1>>s2) {
		string res=stringmul(s1,s2);
		cout<<res<<endl;
	}
	return 0;
}

/*
123 456
000 000
*/

/*
s1="123", 
s2="456"

 0| 1| 2| 3| 4| 5 //index
-------------------------
 0| 0| 0| 0| 0| 0 //initial value of res
  |  |  | 6|12|18
  |  | 5|10|15|
  | 4| 8|12|  |
--------------------------
 0| 5| 6| 0| 8| 8 //final value of res

 s="56088"
 */