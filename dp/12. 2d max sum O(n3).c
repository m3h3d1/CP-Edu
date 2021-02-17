#include<stdio.h>
#include<string.h>
#define m 4
#define n 5
#define db(x) printf("%s is %d\n",#x,x);
//int m,n;
int temp[105];
int maxLeft,maxRight,up,down,maxUp,maxDown;

int max(int x,int y) { return x>y ? x:y; }
int kadane(int arr[][n]){
    int i,j,k,sum,currentMax,maxSum=0,c;
    for(i=0;i<m;i++){
        memset(temp,0,sizeof(temp));
        for(j=i;j<n;j++){
            sum=currentMax=0; c=1;
            for(k=0;k<m;k++){
                temp[k]+=arr[k][j];
                sum+=temp[k];
                /*currentMax=max(currentMax,sum);*/
                if(sum>currentMax){
                    currentMax=sum;
                    if(c){ up=k; c=0; }
                    down=k;
                }
                if(sum<0) sum=0;
            }
            /*printf("L %d, R %d, ",i,j);*/
            /*maxSum=max(maxSum,currentMax);*/
            if(currentMax>maxSum){
                maxSum=currentMax;
                maxLeft=i;
                maxRight=j;
                maxUp=up;
                maxDown=down;
            }
            /*printf("max %d\n",maxSum);*/
        }
    }
    return maxSum;
}
int main(){
    int res;
    //scanf("%d %d",&m,&n);
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
-1 -1 -1 -1 -1
*/
/*
int arr[4][5] ={{ 2, 1,-3,-4, 5},
                { 0, 6, 3, 4, 1},
                { 2,-2,-1, 4,-5},
                {-3, 3, 1, 0, 3}};
*/

/*
Youtube
Maximum Sum Rectangular Submatrix in Matrix dynamic programming/2D kadane

* Write a program to find maximum sum rectangle in give 2D matrix.
* Assume there is at least one positive number in the 2D matrix.

* Solution:
* Keep temp array with size as number of rows. Start left and right from 0
* and keep adding values for each row and maintain them in this temp array.
* Run Kadane's algorithm to find max sum subarray in temp. Now increment right by
* 1. When right reaches last column reset right to 1 and left to 1.

* Space complexity of this algorithm is O(row)
* Time complexity of this algorithm is O(row*col*col)
*/

/*
Better explaination available at
redgreencode
*/