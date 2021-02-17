//knapssack geeks
#include<stdio.h>
#define max(a,b) (a>b ? a:b)

int knapsack(int bag,int val[],int wt[],int n){
	int dp[n+1][bag+1];
	for(int i=0;i<=n;++i){
		for(int w=0;w<=bag;++w){
			if(i==0 || w==0) 
				dp[i][w]=0;

		   // If weight of the nth item is more than Knapsack capacity W,
		   // then, this item cannot be included in the optimal solution
			else if (wt[i-1] > w)
				dp[i][w]=dp[i-1][w];
			
		   // Return the maximum of two cases:
		   // (1) nth item included
		   // (2) not included
			else
				dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
		}
	}
	return dp[n][bag];
}
int main(){
	int n,val[10],wt[10],bag;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&val[i]);
	for(int i=0;i<n;++i) scanf("%d",&wt[i]);
	scanf("%d",&bag); //maximum bag size
	int res=knapsack(bag,val,wt,n);
	printf("%d\n",res);
	return 0;
}

/*
3
60 100 120
10  20  30
50

5
10 120 280 150 200
4   1   4   3   4
10
*/

/*
for
5
10 120 280 150 200
4 1 4 3 4
10

    0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 -10
  .------------------------------------------
0 . 0   0   0   0   0   0   0   0   0   0   0
1 . 0   0   0   0  10  10  10  10  10  10  10
2 . 0 120 120 120 120 130 130 130 130 130 130
3 . 0 120 120 120 280 400 400 400 400 410 410
4 . 0 120 120 150 280 400 400 430 550 550 550
5 . 0 120 120 150 280 400 400 430 550 600 600

*/