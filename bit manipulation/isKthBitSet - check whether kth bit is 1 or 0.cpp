#include<iostream>
using namespace std;

//using left shift
bool isKthBitSet(int n, int k) { 
    if (n & (1 << (k - 1))) 
        return true;
    return false;
}
int main() {
	int n,k;
	cin>>n>>k;
	cout<<isKthBitSet(n,k)<<'\n';
	return 0;
}

/*
using right shift
bool isKthBitSet(int n, int k) { 
    if ((n >> (k - 1)) & 1) 
        return true;
    return false;
}
*/
/*
here for 4:
binary representation is 000000000100
1 th bit is 0
2 th bit is 0
3 th bit is 1
4 th bit is 0
*/