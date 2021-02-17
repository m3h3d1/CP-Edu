//geeks4geeks
#include<stdio.h>
#include<stdlib.h>

int lis(int arr[],int n){
	int *dp,max=0;
	dp=(int*) malloc(n * sizeof(int));
	//initialize LIS values for all indexes
	for(int i=0;i<n;++i) dp[i]=1;
	//compute optimized LIS value in bottom up manner
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			if(arr[i]>arr[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}
	}
	//pick maximum of all LIS values
	for(int i=0;i<n;++i){
		if(dp[i]>max) max=dp[i];
	}
	free(dp); //free memory to avoid memory leak
	return max;
}
int main(){
	int n,arr[100];
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	int res=lis(arr,n);
	printf("Length of LIS is %d\n",res);
	return 0;
}

/*
8
10 22 9 33 21 50 41 60
*/