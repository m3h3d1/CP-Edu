#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);
int square(int x){
    return x*x;
}
int bigMod(int b,int p,int m){
    if(p==0) return 1;
    //or, if(p==1) return b%m;
    else if((p&1)==0){
        return square(bigMod(b,p/2,m))%m;
    }
    else{
        return bigMod(b,p-1,m)%m * b%m;
    }
}
int main(){
    int b,p,m,res;
    while(scanf("%d %d %d",&b,&p,&m) != EOF){
        res=bigMod(b,p,m);
        printf("%d\n",res);
    }
    return 0;
}

/* b^p % m */