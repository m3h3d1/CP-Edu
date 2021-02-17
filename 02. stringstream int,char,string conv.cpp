#include<iostream>
#include<sstream>
using namespace std;

void int_string() {
	///int to string
	stringstream ss;
	int a = 1234;
	ss<<a;  /// stream in
	string s1;
	ss>>s1; /// stream out
	//or string s1 = ss.str()
	cout<<s1<<endl;

	///string to int
	ss.clear();
	string s = "1234";
	ss<<s;
	int b;
	ss>>b;
	cout<<b<<endl;
}

void char_string(){
	/// char* to string
	stringstream ss;
	char somechars[10] = "ruet cse";
	ss<<somechars;
	string somestrings;
	ss>>somestrings;
	cout<<somestrings<<endl;

	/// string to char*
	ss.clear();
	somestrings = "ruet cse";
	ss<<somestrings;
	ss>>somechars;
	cout<<somechars<<endl;
}

int main() {
	int_string();
	char_string();
	return 0;
}