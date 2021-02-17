/*time O(n*r) space O(r)*/
#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b ? a:b)
#define db(x) printf("%s is %d\n",#x,x);

int nCr(int n,int r){
    int* C=(int*)calloc(r+1,sizeof(int));
    int i,j,res;
    C[0]=1;
    for(i=1;i<=n;i++){
    	for(j=min(i,r);j;j--){
    		C[j]=C[j] + C[j-1];
            /*db(C[j]);*/
    	}
    }
    res=C[r];
    free(C);
    return res;
}
int main(){
    int n,r;
    while(scanf("%d %d",&n,&r) != EOF){
        printf("%d\n",nCr(n,r));
    }
    return 0;
}