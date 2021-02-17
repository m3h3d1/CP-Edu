#include<iostream>
using namespace std;

bool palin(string str){
	return equal(str.begin(),str.begin()+str.size()/2,str.rbegin());
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
abadaba
*/

/*
equal accepts three inputs – two iterators delineating a
range and a third iterator indicating the start of a second range – then returns whether the two ranges are
equal. 
*/