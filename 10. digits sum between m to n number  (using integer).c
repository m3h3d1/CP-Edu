#include<stdio.h>
int main(){
	unsigned long long T,a,b,i,sum,n;
	scanf("%llu",&T);
	while(T--){
		sum=0;
		scanf("%llu %llu",&a,&b);
		for(i=a;i<=b;i++){
			n=i;
			while(n!=0){
				sum+=n%10;
				n/=10;
			}
		}
		printf("%llu\n",sum);
	}
	return 0;
}