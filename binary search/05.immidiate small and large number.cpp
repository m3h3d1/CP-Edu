#include<iostream>
using namespace std;
int l,r;
int arr[50005];

int bslowerbound(int arr[],int x,int a,int b) {
	l=a,r=b;
	int idx=-1;
	while(l<=r) {
		int mid=l+(r-l)/2;
		if(arr[mid]>=x){
			if(arr[mid]==x) idx=mid;
			r=mid-1;
		}
		else if(arr[mid]<x) l=mid+1;
	}
	return idx;
}
int bsupperbound(int arr[],int x,int a,int b) {
	l=a,r=b;
	int idx=-1;
	while(l<=r) {
		int mid=l+(r-l)/2;
		if(arr[mid]<=x){
			if(arr[mid]==x) idx=mid;
			l=mid+1;
		}
		else if(arr[mid]>x) r=mid-1;
	}
	return idx;
}
int main() {
	int n,q,x,n1,n2,idx;
	while(cin>>n) {
		for(int i=0;i<n;++i) cin>>arr[i];
		cin>>q;
		for(int i=0;i<q;++i) {
			cin>>x;
			idx=bslowerbound(arr,x,0,n-1);
			if(idx==-1) n1=l-1;
			else n1=idx-1;

			idx=bsupperbound(arr,x,0,n-1);
			if(idx==-1) n2=r+1;
			else n2=idx+1;

			if(n1>=0 && n1<n) cout<<arr[n1]<<" ";
			else cout<<"X ";
			if(n2>=0 && n2<n) cout<<arr[n2]<<endl;
			else cout<<"X"<<endl;
		}
	}
	return 0;
}

/*
uva 10611 playboy chimp

4
1 4 5 7
4
4 6 8 10
*/