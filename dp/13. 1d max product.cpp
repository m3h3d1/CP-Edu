#include<iostream>
using namespace std;

long long maxproduct(long long arr[],int n) {
	long long maxval=arr[0];
	long long minval=arr[0];
	long long maxprod=arr[0];
	for(int i=1;i<n;++i) {
		if(arr[i]<0) swap(maxval,minval);
		maxval=max(arr[i],maxval*arr[i]);
		minval=min(arr[i],minval*arr[i]);
		maxprod=max(maxprod,maxval);
	}
	return maxprod;
}
int main() {
	long long n,arr[20];
	cin>>n;
	for(int i=0;i<n;++i) cin>>arr[i];
	long long res=maxproduct(arr,n);
	if(res<0) res=0;
	cout<<"The maximum product is "<<res<<"."<<endl;
	return 0;
}

/*
5
6 -3 -10 0 2

5
-1 -3 -10 0 60

5
-2 -3 0 -2 -40

3
0 2 0
*/

/*
https://www.geeksforgeeks.org/maximum-product-subarray-set-3/

The idea is to traverse array from left to right keeping two variables minVal and maxVal
which represents the minimum and maximum product value till the ith index of the array. 
Now, if the ith element of the array is negative that means now the values of minVal and maxVal 
will be swapped as value of maxVal will become minimum by multiplying it with a negative number. 
Now, compare the minVal and maxVal.

The value of minVal and maxVal depends on the current index element or the product of the current 
index element and the previous minVal and maxVal respectively.
*/