#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);
int x,y,d;

void extendedEuclid(int a,int b){
    if(b==0){
        x=1; y=0; d=a;
        return;
    }
    extendedEuclid(b,a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}
int main(){
    int T,a,n,i;
    while(scanf("%d",&n) != EOF){

    }
    return 0;
}