#include<bits/stdc++.h>
using namespace std;

void count_sort(int A[], int n, int x) {
	int cnt[10]={0}, tmp[n];
	
	// Count the number of times each digit occurred at (exp)th place in every input.
	for(int i=0;i<n;++i) {
		cnt[(A[i]/x)%10]++;
	}
	
	// Calculating their cumulative count.
	for(int i=1;i<10;++i) {
		cnt[i] += cnt[i-1];
	}

	// Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
	for(int i=n-1;i>=0;--i) {
		tmp[cnt[(A[i]/x)%10]-1] = A[i];
		cnt[(A[i]/x)%10]--;
	}

	// Assigning the result to the arr pointer of main().
	for(int i=0;i<n;++i) {
		A[i] = tmp[i];
	}
	// for(int i=0;i<n;++i) cout<<A[i]<<" ";
	// cout<<endl;
}
void radix_sort(int A[], int n, int maxx) {
	for(int mul=1;maxx/mul>0;mul*=10) {
		count_sort(A, n, mul);
	}
}
int main() {
	int a,b,n,T,cas=0;
	int A[100];
	cin>>n;
	int maxx = INT_MIN;
	for(int i=0;i<n;++i) {
		cin>>A[i];
		if(A[i]>maxx) maxx = A[i];
	}
	//cout<<maxx<<endl<<endl;
	radix_sort(A, n, maxx);
	for(int i=0;i<n;++i) cout<<A[i]<<" ";
	return 0;
}

/*
12
73 32 72 49 45 33 45 29 7 28 99 31
*/

/*
Problem Description
1. In this algorithm sorting of data is done from least significant digit to most significant digit.
2. Here we need 10 different spaces labeled 0 to 9.
3. Assume we have ‘n’ number of inputs.
4. Let ‘d’ be the maximum number of digit the input data has.
5. The time complexity for radix sort is O(n*d).
6. Radix sort solves the problem of card sorting by sorting on the least significant digit first.

Problem Solution
1. Get the maximum value from the input array which has ‘d’ digits.
2. Starting from least significant digit, sort the data.
3. Take this data as input for next significant digit.
4. Run the iteration till d digit.
5. Display the result.
6. Exit.
*/

/*
RADIX_SORT (A, d)
	for i ← 1 to d do
	    use a stable sort to sort A on digit i
	    // counting sort will do the job
*/

/*
Analysis
The running time depends on the stable used as an intermediate sorting algorithm. When each digits is in the range 1 to k, and k is not too large, COUNTING_SORT  is the obvious choice.
In case of counting sort, each pass over n d-digit numbers takes O(n + k) time. There are d passes, so the total time for Radix sort is (n+k) time. 
There are d passes, so the total time for Radix sort is  (dn+kd). When d is constant and k =  (n), the Radix sort runs in linear time.
*/