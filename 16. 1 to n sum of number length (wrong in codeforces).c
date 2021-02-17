#include<stdio.h>
#include<math.h>
int main(){
    long long a,i,cnt,d,p;
    cnt=0;
    scanf("%lld",&a);
    for(d=1;;d++){
    	p=pow(10,d)-1;
    	if(p<a) cnt+=9*pow(10,d-1)*d;
    	else{
    		cnt+=(a-pow(10,d-1)+1)*d;
    		break;
    	}
    }
    printf("%lld\n",cnt);
    return 0;
}