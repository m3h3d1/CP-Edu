#include<bits/stdc++.h>
using namespace std;

void bucketSort(double A[], int n) {
	vector<double> bucket[n];
	for(int i=0;i<n;++i) {
		bucket[int(n*A[i])].push_back(A[i]);
	}
	for(int i=0;i<n;++i) {
		sort(bucket[i].begin(), bucket[i].end());
	}
	int k=0;
	for(int i=0;i<n;++i) {
		for(int j=0;j<bucket[i].size();++j) {
			A[k++] = bucket[i][j];
		}
	}
}
int main() {
	int n;
	cin>>n;
	double A[n];
	for(int i=0;i<n;++i) cin>>A[i];
	bucketSort(A, n);
	for(int i=0;i<n;++i) cout<<A[i]<<" ";
	return 0;
}

/*
10
0.25 0.36 0.58 0.41 0.29 0.22 0.45 0.79 0.01 0.69
*/

/*
BUCKET_SORT(A)
	let B[0..n-1] be a new array
	n = A.length
	for I = 0 to n-1
		make B[i] an empty list
	for i=1 to n
		insert a[i] into b[floor(n*a[i])]
	for I = 0 to n-1
		sort b[i] using insertion sort
	concatenate list b[0],b[1]…b[n-1] together in order

// Algorithm source from Introduction to Algorithms by CLRC
*/

/*
T(n) = [time to insert n elements in array A] + [time to go through auxiliary array B[0 . . n-1] * (Sort by INSERTION_SORT)
       = O(n) + (n-1)  (n)
       = O(n)
*/