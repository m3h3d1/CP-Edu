#include<iostream>
#include<algorithm> //remove_if
#include<sstream>
#include<vector>
#include<iterator> //istream_iterator
using namespace std;

bool notalpha_space(char ch) {
	return !isalpha(ch) && !isspace(ch);
}
bool palin(string &str){
	str.erase(remove_if(str.begin(),str.end(), notalpha_space),str.end());
	transform(str.begin(),str.end(),str.begin(),::tolower);

	stringstream tokenizer(str);
	vector<string> tokens;
	tokens.insert(tokens.begin(),istream_iterator<string> (tokenizer),istream_iterator<string>() );
	//same as, string token; while(tokenizer >> token) tokens.push_back(token);
	
	return equal(tokens.begin(),tokens.begin()+tokens.size()/2,tokens.rbegin());
}
int main(){
	string str;
	while(getline(cin,str)) {
		if(palin(str)) cout<<"palindrome"<<endl;
		else cout<<"not palindrome"<<endl;
	}
}

/*
This is this
It's an its
Hello? Hello!? HELLO?
*/