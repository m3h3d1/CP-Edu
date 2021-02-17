#include<stdio.h>
#include<string.h>
#define m 4
#define n 5
#define max(a,b) (a>b ? a:b)
int temp[105];

int kadane(int arr[][n]){
    int sum,currentMax,maxSum=0,allneg=1;
    for(int i=0;i<m;i++){
        memset(temp,0,sizeof(temp));
        for(int j=i;j<n;j++){
            sum=currentMax=0;
            for(int k=0;k<m;k++){
                temp[k]+=arr[k][j];
                sum+=temp[k];
                if(sum<0) sum=0;
                else if(sum>currentMax){
                    currentMax=sum;
                }
            }
            if(currentMax>maxSum){
                maxSum=currentMax;
                allneg=0;
            }
        }
    }
    //handling all negative numbers
    if(allneg){
        maxSum=arr[0][0];
        for(int i=0;i<m;++i) for(int j=0;j<n;++j){
            if(arr[i][j]>maxSum) {
                maxSum=arr[i][j];
            }
        }
    }
    return maxSum;
}
int main(){
    int res;
    int arr[m][n];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++){
        scanf("%d",&arr[i][j]);
    }
    res=kadane(arr);
    printf("max sum %d\n",res);
    return 0;
}
/*
 2  1 -3 -4  5
 0  6  3  4  1
 2 -2 -1  4 -5
-3  3  1  0  3
*/
/*
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -0
*/