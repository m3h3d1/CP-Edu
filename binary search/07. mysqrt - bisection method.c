#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

double mysqrt(double x){
    double lo=0.0,hi=x,mid;
    while(hi-lo>0.00000001){ /* or, while step<64 */
        mid=(lo+hi)/2;
        if(mid*mid>x) hi=mid;
        else lo=mid;
    }
    return mid;
}
int main(){
    int n;
    double res;
    while(scanf("%d",&n) != EOF){
        res=mysqrt(n);
        printf("%.10lf\n", res);
    }
    return 0;
}