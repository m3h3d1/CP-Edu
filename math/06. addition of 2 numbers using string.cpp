#include<stdio.h>
#include<iostream>
#include<algorithm>
#define db(x) cout << (#x) <<" is "<< (x) << '\n'
using namespace std;

string sum(string s1,string s2){
	int i,carry,sum,diff;
	if(s1.length()<s2.length()) swap(s1,s2); //length of 1st string is larger
	string str="";
	int l1=s1.length(),l2=s2.length();
	diff=l1-l2;
	carry=0;
	for(i=l2-1;i>=0;i--){
		sum=(s1[i+diff]-'0')+(s2[i]-'0')+carry;
		str.push_back(sum%10+'0');
		carry=sum/10;
	}
	//add remaining digits of s2
	for(i=diff-1;i>=0;i--){
		sum=(s1[i]-'0')+carry;
		str.push_back(sum%10+'0');
		carry=sum/10;
	}
	//add remaining carry
	if(carry){
		str.push_back(carry+'0');
	}
	reverse(str.begin(),str.end());
	return str;
}
int main(){
	ios_base::sync_with_stdio(false);
	string first,sec;
	while(cin>>first>>sec){
		cout<<sum(first,sec)<<'\n';
	}
	return 0;
}