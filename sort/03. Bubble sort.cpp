#include<iostream>
using namespace std;
int cnt;
// void swap(int *x,int *y) {
// 	int temp=*x;
// 	*x=*y;
// 	*y=temp;
// }
void bubble(int arr[],int n) {
	for(int i=0;i<n-1;++i) {
		for(int j=i+1;j<n;++j) {
			if(arr[j]<arr[i]) {
				swap(arr[i],arr[j]);
				cnt++;
			}
		}
	}
}
int main() {
	int n;
	int arr[100];
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	bubble(arr,n);
	for(int i=0;i<n;++i) cout<<arr[i]<<" ";
	cout<<endl<<cnt;
	return 0;
}

/*
10
8 5 9 2 6 3 7 1 10 4

6
3 -5 1 10 4 77
*/