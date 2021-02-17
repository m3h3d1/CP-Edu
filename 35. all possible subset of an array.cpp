#include<bits/stdc++.h>
using namespace std;

void allPossibleSubset(int arr[], int n) {
	int cnt = (1<<n);

	// The outer for loop will run 2^n times to print all subset .
	for(int i=0; i < cnt; ++i) {

		//The inner for loop will run n times , As the maximum number of elements a set can have is n
		// This loop will generate a subset
		for(int j=0;j<n;++j) {

			// check if jth bit in binary representation of  i  is set or not. 
			// if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
			// otherwise exclude arr[j]
			if( (i&(1<<j)) > 0) {
				cout<<arr[j]<<" ";
			}
		}
		cout<<endl;
	}
}
int main() {
	int n, arr[10];
	cin>>n;
	for(int i=0;i<n;++i) cin>>arr[i];
	allPossibleSubset(arr, n);
	return 0;
}

/*
4
1 2 3 4
*/