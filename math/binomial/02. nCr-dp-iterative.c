/*time O(n*r) space O(n*r)*/
#include<stdio.h>
#define min(a,b) (a<b ? a:b)
#define db(x) printf("%s is %d\n",#x,x);

int nCr(int n,int r){
    int C[n+1][r+1];
    int i,j;
    for(i=0;i<=n;i++){
    	for(j=0;j<=min(i,r);j++){
    		if(j==0 || j==i) C[i][j]=1;
    		else C[i][j]=C[i-1][j-1] + C[i-1][j];
    		/*db(C[i][j]);*/
    	}
    }
    return C[n][r];
}
int main(){
    int T,a,n,r;
    while(scanf("%d %d",&n,&r) != EOF){
        printf("%d\n",nCr(n,r));
    }
    return 0;
}