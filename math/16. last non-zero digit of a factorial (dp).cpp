#include<iostream>
#include<iomanip>
using namespace std;

int lastnonzero(int n) {
	int temp=1;
	for(int i=1;i<=n;++i) {
		temp*=i;
		while(temp%10==0) temp/=10;
		temp%=100000;
	//Must keep at least the last five non-zero bits (more than five bits should pay attention to the int type overflow,
	//so take the five best), because the last five non-zero carry (limit case 3125, ie 5^5) will affect the last non-zero position
	}
	return temp%=10;
}
int main() {
	int a,b,n;
	while(cin>>n) {
		int x=lastnonzero(n);
		cout<<setw(5)<<n<<" -> "<<x<<endl;
	}
	return 0;
}

/*
Input to the program is a series of nonnegative integers not exceeding 10000

1
2
26
125
3125
9999
*/