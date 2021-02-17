#include<iostream>
#include<map>
using namespace std;

int main() {
	multimap<int, int> mmp;
	mmp.insert(make_pair(3, 3));
	mmp.insert({3, 12}); // shorter syntax
	mmp.insert({3, 4});
	mmp.insert({3, 15});
	cout << mmp.count(3) << endl; // prints 4
	return 0;
}