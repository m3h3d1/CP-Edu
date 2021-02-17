#include<iostream>
#include<algorithm>
using namespace std;

int bs(int arr[],int n, int key) {
	int *lo=lower_bound(arr,arr+n,key);
	int *hi=upper_bound(arr,arr+n,key);
	cout<<lo-arr<<" "<<hi-arr-1<<endl;
	cout<<arr[lo-arr]<<" "<<arr[hi-arr-1]<<endl;
	cout<<"Total occurances of "<<key<<": "<<(hi-arr) - (lo-arr)<<endl;
}
int main() {
	int n=9;
	int arr[]={2,2,5,5,5,5,5,8,9}; //sorted array
	cout<<binary_search(arr,arr+n,5)<<endl;
	bs(arr,n,5);
	cout<<endl;
	cout<<binary_search(arr,arr+n,4)<<endl;
	bs(arr,n,4);
	return 0;
}
/*
lower_bound
	Return iterator to lower bound
upper_bound
	Return iterator to upper bound
binary_search
	Test if value exists in sorted sequence
*/