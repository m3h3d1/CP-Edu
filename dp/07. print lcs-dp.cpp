#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<iostream>
using namespace std;
#define mxn 1000
#define db(x) printf("%s is %d\n",#x,x);
char s1[mxn],s2[mxn];
int l1,l2;
int dp[mxn][mxn];
bool visited[mxn][mxn];

int max(int x,int y) { return x>y ? x:y; }
int lcs(int i,int j){
	if(s1[i]=='\0' || s2[j]=='\0') return 0;
	if(visited[i][j]) return dp[i][j];

	int res=0;
	if(s1[i]==s2[j]) res=1+lcs(i+1,j+1);
	else res=max(lcs(i+1,j), lcs(i,j+1));
	dp[i][j]=res;
	visited[i][j]=1;
	return dp[i][j];
}
string ans;
void printLCS(int i,int j){
    if(s1[i]=='\0' or s2[j]=='\0'){
        cout<<ans<<endl;
        return;
    }
    if(s1[i]==s2[j]){
        ans+=s1[i];
        printLCS(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}
void printAll(int i,int j){
	if(s1[i]=='\0' || s2[j]=='\0'){
		cout<<ans<<endl;
		return;
	}
	if(s1[i]==s2[j]){
		ans+=s1[i];
		printAll(i+1,j+1);
		ans.erase(ans.end()-1); // delete last char
	}
	else{
		if(dp[i+1][j]>dp[i][j+1]) printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(i,j+1);
		else{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}
int main(){
	while(scanf("%s %s",s1,s2) != EOF){
		memset(dp,0,sizeof(dp)); /* na dileo hoy ei line*/
		memset(visited,0,sizeof(visited));
		ans.clear();
		l1=strlen(s1);
		l2=strlen(s2);
		printf("%d\n",lcs(0,0));
		printLCS(0,0);
		ans.clear();
		printAll(0,0);
	}
	return 0;
}

/*
shafayetsplanet
abcdef
defabc
*/