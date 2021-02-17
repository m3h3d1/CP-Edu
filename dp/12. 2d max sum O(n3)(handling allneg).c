#include<stdio.h>
#include<string.h>
#define m 4
#define n 5
#define max(a,b) (a>b ? a:b)
int temp[105];
int maxLeft,maxRight,up,down,maxUp,maxDown;

int kadane(int arr[][n]){
    int i,j,k,sum,currentMax,maxSum=0,c,allneg=1;
    for(i=0;i<m;i++){
        memset(temp,0,sizeof(temp));
        for(j=i;j<n;j++){
            sum=currentMax=0; c=1;
            for(k=0;k<m;k++){
                temp[k]+=arr[k][j];
                sum+=temp[k];
                if(sum>currentMax){
                    currentMax=sum;
                    if(c){ up=k; c=0; }
                    down=k;
                }
                if(sum<0) sum=0;
            }
            if(currentMax>maxSum){
                maxSum=currentMax;
                maxLeft=i;
                maxRight=j;
                maxUp=up;
                maxDown=down;

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

                maxLeft=i;
                maxUp=j;
                maxRight=i;
                maxDown=j;
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
    printf("(L U) (%d %d)\n(R D) (%d %d)\n",maxLeft,maxUp,maxRight,maxDown);
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