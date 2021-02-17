#include<iostream>
#include<cstring>
using namespace std;

int arr[105];
void pfactors(int num) {
	for(int i=2;i<=num;++i) {
		int n=i;
		for(int j=2;j*j<=n;++j) {
			while(n%j==0) {
				arr[j]++;
				n/=j;
			}
		}
		if(n!=1) arr[n]++;
	}
}
int main() {
	int a,b,n,T,cas=0;
	cin>>T;
	while(T--) {
		cin>>n;
		memset(arr,0,sizeof(arr));
		pfactors(n);
		printf("Case %d: %d =",++cas,n);
		if(arr[2]) printf(" %d (%d)",2,arr[2]);
		for(int i=3;i<=n;i+=2) {
			if(arr[i]) {
				printf(" * %d (%d)",i,arr[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

/*
3
2
3
6
*/