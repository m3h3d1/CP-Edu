#include<iostream>
#include<vector>
#include<iterator> //ostream_iterator
using namespace std;

int main() {
	vector<int> v={561,222,2323,34}, vCopy;
	copy(v.begin(),v.end(),back_inserter(vCopy));
	for(auto x: vCopy) cout<<x<<" ";
	cout<<endl<<endl;
	
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	return 0;
}