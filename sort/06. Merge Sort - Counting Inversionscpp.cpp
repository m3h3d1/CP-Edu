#include<iostream>
#include<climits>
#include<vector>
using namespace std;
long long cnt;

void merge(int arr[], int l, int m, int r) {
	int n1 = m-l+1;
	int n2 = r-m;
	vector<int> L(n1+1), R(n2+1);
	L.assign(arr+l,arr+l+n1);
	R.assign(arr+m+1,arr+m+1+n2);
	L[n1] = R[n2] = INT_MAX;
	int i=0, j=0;
	for(int k=l;k<=r;++k) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			if(i < n1) cnt+=(n1-i);
			j++;
		}
	}
	L.clear(), R.clear();
}
void mergesort(int arr[], int l, int r) {
	if(l<r) {
		int m = (l+r)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main() {
	int a,b,n,T;
	int arr[100005];
	scanf("%d",&T);
	while(T--) {
		cnt = 0;
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",&arr[i]);
		mergesort(arr,0,n-1);
		printf("%lld\n",cnt);
	}
	return 0;
}

/*
2  

5  
1 1 1 2 2  

5  
2 1 3 1 2
*/

/*
Hacker rank:- Merge Sort: Counting Inversions

*/