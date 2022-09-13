#include<bits/stdc++.h>
using namespace std;
int mx = 0;

void countSort(int A[], int B[], int n) {
	int C[mx+1]={0};
	for(int i=1;i<=n;++i) { //fequency counting 
		C[A[i]]++;
	}
	for(int i=1;i<=mx;++i) { //stores the last occurence of the element i
		C[i]+=C[i-1];
	}
	for(int i=n;i>=1;--i) {
		B[C[A[i]]] = A[i]; //It will place the elements at their respective index
		C[A[i]]--; //decrease count for same numbers
	}
}
int main() {
	int n;
	cin>>n;
	int A[n+1], B[n+1];
	for(int i=1;i<=n;++i) {
		cin>>A[i];
		if(A[i]>mx) mx = A[i];
	}
	countSort(A, B, n);
	for(int i=1;i<=n;++i) cout<<B[i]<<" ";
	return 0;
}

/*
12
12 100 345 89 100 23 0 18 44 111 100 1
*/

/*
COUNTING_SORT (A, B, k)
	1.	for i ← 1 to k do
	2.	    c[i] ← 0
	3.	for j ← 1 to n do
	4.	    c[A[j]] ← c[A[j]] + 1
	5.	// c[i] now contains the number of elements equal to i
	6.	for i ← 2 to k do
	7.	    c[i] ← c[i] + c[i-1]
	8.	// c[i] now contains the number of elements ≤ i
	9.	for j ← n downto 1 do
   10.	    B[c[A[i]]] ← A[j]
   11.	    c[A[i]] ← c[A[j]] - 1
*/

/*
Analysis
The loop of lines 1-2   takes O(k) time
The loop of lines 3-4   takes O(n) time
The loop of lines 6-7   takes O(k) time
The loop of lines 9-11 takes O(n) time
Therefore, the overall time of the counting sort is O(k) + O(n) + O(k) + O(n) = O(k + n)

 

In practice, we usually use counting sort algorithm when have k = O(n), in which case running time is O(n).

The Counting sort is a stable sort i.e., multiple keys with the same value are placed in the sorted array in the same order that they appear in the input array.

Suppose that the for-loop in line 9 of the Counting sort is rewritten:

9    for j ← 1 to n

then the stability no longer holds. Notice that the correctness of argument in the CLR does not depend on the order in which array A[1 . . n] is processed. 
The algorithm is correct no matter what order is used. In particular, the modified algorithm still places the elements with value k in position c[k - 1] + 1 through c[k], but in reverse order of their appearance in A[1 . . n].

Note that Counting sort beats the lower bound of  Ω(n lg n), because it is not a comparison sort. There is no comparison between elements. Counting sort uses the actual values of the elements to index into an array.
*/