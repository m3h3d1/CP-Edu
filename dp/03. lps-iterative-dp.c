#include<stdio.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);

int max(int x,int y) { return x>y ? x:y; }
int lps(char *str){
    int n=strlen(str);
    int i,j,k;
    int dp[n][n];
    //Strings of length 1 are palindrome of lentgh 1
    for(i=0;i<n;i++) dp[i][i]=1;
    //similar to dp matrix chain multiplication
    //k is length of substring (cl-chain length)
    for(k=2;k<=n;k++){
    	for(i=0;i<n-k+1;i++){
    		j=i+k-1;
    		if(str[i]==str[j] && k==2) dp[i][j]=2;
    		else if(str[i]==str[j]) dp[i][j]=dp[i+1][j-1]+2;
    		else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
    	}
    }
    return dp[0][n-1];
}
int main(){
    char str[100];
    scanf("%s",str);
    int res=lps(str);
    printf("The length of the lps is %d\n",res);
    return 0;
}
/*
geeksforgeeks
babcbab
*/
/* geeksforgeeks: 
longest palindromic subsequence 
*/