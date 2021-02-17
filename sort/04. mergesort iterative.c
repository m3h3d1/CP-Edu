#include<stdio.h>

//L[l..m] + R[m+1..r] --> arr[l..r]
void merge(int arr[],int l,int m,int r){
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];

	//copy data to temp arrays
	for(int i=0;i<n1;++i) L[i]=arr[l+i];
	for(int i=0;i<n2;++i) R[i]=arr[m+1+i];

	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			++i;
		}
		else{
			arr[k]=R[j];
			++j;
		}
		++k;
	}

	//copy remaining,if there any
	while(i<n1){
		arr[k]=L[i];
		++i;++k;
	}
	while(j<n2){
		arr[k]=R[j];
		++j;++k;
	}
}
void mergesort(int arr[],int l,int r){
	if(l<r){
		//same as (l+r)/2, but avoids overflow for large l,r
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}
int main(){
	int n,arr[100];
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	for(int i=0;i<n;++i) printf("%d ",arr[i]);
	return 0;
}

/*
6
12 11 13 5 6 7

15
34535 345 3 345 34 52315 6567 7 5 45 6 8 9 6 999
*/
//geeks4geeks