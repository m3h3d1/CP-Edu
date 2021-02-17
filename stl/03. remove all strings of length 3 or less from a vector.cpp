//7. Using remove_if and a custom callback function, write a function RemoveShortWords that
//accepts a vector<string> and removes all strings of length 3 or less from it.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool shortWords(string str) {
	return str.size()<=3;
}
void removeShortWords(vector<string> &v) {
	v.erase(remove_if(v.begin(),v.end(),shortWords),v.end());
}
int main() {
	string str;
	vector<string> v; 
	for(int i=0;i<5;++i) {
		cin>>str;
		v.push_back(str);
	}
	removeShortWords(v);
	for(auto i=0;i<v.size();++i) cout<<v[i]<<" ";
	return 0;
}

/*
how
an
hello
mello
a
*/