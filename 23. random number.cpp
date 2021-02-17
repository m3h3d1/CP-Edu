#include<iostream>
#include<time.h>
using namespace std;

int main() {
	cout<<time(NULL)<<endl;
	srand(time(NULL));
	int n=20;
	for(int i=0;i<n;++i) {
		cout<<rand()<<endl; //rand() -> 0 to 32767
	}
	return 0;
}