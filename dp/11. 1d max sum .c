#include<stdio.h>

int maxSubArraySum(int arr[],int n){
	int max=0,sum=0;
	for(int i=0;i<n;++i){
		sum+=arr[i];
		if(sum<0) sum=0;
		else if(max<sum) max=sum;
	}
	return max;
}
int main(){
	int n,arr[100];
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	int res=maxSubArraySum(arr,n);
	printf("%d\n",res);
	return 0;
}
//Largest Sum Contiguous Subarray
/*
9
1 2 3 4 5 6 7 8 9

3
-1 -1 -1

5
23 -1 -24 2 23

7
1 -14 -4 14 -11 -7 6

8
-2 -3 4 -1 -2 1 5 -3
*/