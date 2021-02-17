#include<iostream>
using namespace std;

bool palin(string str){
	for(int i=0,j=str.size()-1;i<j;i++,j--){
		if(str[i]!=str[j]) return 0;
	}
	return 1;
}
int main(){
	string str;
	cin>>str;
	if(palin(str)) cout<<"palindrome"<<endl;
	else cout<<"not palindrome"<<endl;
}

/*
madam
adam
*/