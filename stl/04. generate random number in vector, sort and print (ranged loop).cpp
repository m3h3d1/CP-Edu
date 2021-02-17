#include<iostream>
#include<vector>
#include<algorithm> //rand, sort
#include<iterator> //ostream_iterator
using namespace std;

int main() {
	const int mxn = 100;
	vector<int> vec(mxn);
	generate(vec.begin(), vec.end(), rand);
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout," "));
	cout<<endl;
	
	for(auto a: vec) {
		cout<<a<<" ";
	}
	return 0;
}