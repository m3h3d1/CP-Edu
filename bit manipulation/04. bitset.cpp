#include<iostream>
#include<bitset>
using namespace std;

int main() {
	int n;
	bitset<4> b;
	cout<<b<<endl;
	cout<<b.flip(1)<<endl;
	cout<<b.flip()<<endl; //flips
	b = ~b; //NOT
	cout<<b<<endl;
	int a = b.to_ulong(); //converts (c++11 supports to_ullong)
	cout<<a<<endl;

	cout<<b.reset()<<endl; //resets
	
	bitset<4> x("0110");
	bitset<4> y("0011");
	cout<<"x & y: "<<(x & y)<<endl; //AND
	cout<<"x | y: "<<(x | y)<<endl; //OR
	cout<<"x ^ y: "<<(x ^ y)<<endl; //XOR
	return 0;
}