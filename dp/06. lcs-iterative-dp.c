//geeks4geeks
#include<stdio.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);

int max(int a,int b){
	return (a>b)? a:b;
}
int lcs(char x[],char y[],int m,int n){
	int dp[m+1][n+1];
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n;++j){
			if(i==0 || j==0) dp[i][j]=0;
			else if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}
int main(){
	char s1[100],s2[100];
	scanf("%s %s",s1,s2);
	int l1=strlen(s1);
	int l2=strlen(s2);
	printf("Length of LCS is %d\n",lcs(s1,s2,l1,l2));
	return 0;
}

/*
aggtab
gxtxayb
*/