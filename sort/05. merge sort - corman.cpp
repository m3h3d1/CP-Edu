#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;
int cnt_cmp;

void merge(int arr[], int l, int m, int r) {
	int n1 = m-l+1;
	int n2 = r-m;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	for(int i=0;i<n1;++i) L[i] = arr[l+i];
	for(int i=0;i<n2;++i) R[i] = arr[m+1+i];
	L[n1] = R[n2] = INT_MAX;
	int i=0, j=0;
	for(int k=l;k<=r;++k) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		cnt_cmp++;
	}
	delete[] L;
	delete[] R;
}
void mergesort(int arr[], int l, int r) {
	if(l < r) {
		int m = (l+r)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main() {
	int a,b,n,T;
	cnt_cmp = 0;
	scanf("%d",&n);
	int *arr = new int[n];
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	for(int i=0;i<n;++i) {
		if(i) printf(" ");
		printf("%d",arr[i]);
	}
	printf("\n%d\n",cnt_cmp);
	return 0;
}

/*
10
8 5 9 2 6 3 7 1 10 4
*/