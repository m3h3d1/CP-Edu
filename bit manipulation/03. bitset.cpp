#include<iostream>
#include<bitset>
using namespace std;

int main() {
	int a,b,n;
	scanf("%d",&n);
	bitset<8> btf[4];
	for(int i=0;i<n;++i) {
		cin>>a;
		btf[i] = a;
	}

	for(int i=0;i<n;++i) {
		cout<<btf[i]<<" -> "<<btf[i].count()<<endl; //prints binary representation and number of bit set
		for(int j=0;j<btf[i].size();++j) {
			printf("%d", btf[i].test(j)); //test returns bit value
		}
		printf("\n");
	}

	printf("\n");
	cout<<btf[0].set()<<endl;
	cout<<btf[0].set(2,0)<<endl; //sets 0 at no.2 index
	cout<<btf[0].set(2)<<endl; //sets 1 at n0.2 index
	return 0;
}

/*
4
2 3 8 15
*/