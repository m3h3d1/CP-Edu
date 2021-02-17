#include<iostream>
#include<algorithm> //remove_if
using namespace std;

bool notalpha(char ch) {
	return !isalpha(ch);
}
bool palin(string &str){
	str.erase(remove_if(str.begin(),str.end(), notalpha),str.end());
	transform(str.begin(),str.end(),str.begin(),::tolower); //:: is must
	cout<<str<<"=> ";
	return equal(str.begin(),str.begin()+str.size()/2,str.rbegin());
}
int main(){
	string str;
	while(getline(cin,str)) {
		if(palin(str)) cout<<"palindrome"<<endl;
		else cout<<"not palindrome"<<endl;
	}
}

/*
madam
adam
abadaba
RA.CEc!ar
“Did mom pop? Mom did!”
*/