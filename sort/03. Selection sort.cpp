#include<iostream>
using namespace std;
int cnt;

void selection_sort(int arr[], int n) {
	for(int i=0;i<n-1;++i) {
		int min = arr[i], pos = i;
		for(int j=i+1;j<n;++j) {
			if(arr[j]<min) {
				min = arr[j];
				pos = j;
			}
		}
		if(pos != i) {
			swap(arr[i], arr[pos]);
			cnt++;
		}
	}
}
int main() {
	int a,b,n,T;
	int arr[100005];
	cnt = 0;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	selection_sort(arr,n);
	for(int i=0;i<n;++i) printf("%d ",arr[i]);
	printf("\nminimum swaps: %d\n",cnt);
	return 0;
}

/*
10
8 5 9 2 6 3 7 1 10 4
*/