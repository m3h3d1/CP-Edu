#include<stdio.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);
int used[20],number[20];

void permutation(int at,int n){
    int i;
    if(at==n+1){
        /*db(at);*/
        for(i=1;i<=n;i++) printf("%d ",number[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++) if(!used[i]){
        used[i]=1;
        number[at]=i;
        /*db(i);*/
        permutation(at+1,n);
        used[i]=0;
    }
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        memset(used,0,sizeof(used));
        permutation(1,n); /* call with permutation(1,n) */
    }
    return 0;
}