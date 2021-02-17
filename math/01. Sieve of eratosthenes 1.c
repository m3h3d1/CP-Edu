#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define db(x) printf("%s is %d\n",#x,x);
#define MX 65000
bool prime[MX+1];

void sieve(){
	prime[0]=prime[1]=1;
	int i,j,sq=sqrt(MX);
	for(i=4;i<=MX;i+=2) prime[i]=1; /*no need of this line if need to store primes in an array */
	for(i=3;i<=sq;i+=2){
		if(!prime[i]){
			for(j=i*i;j<=MX;j+=i<<1) { /*i*2 because, eg. 3*2=6, 3*3=9, 3*4=12, 3*5=15, here we don't need of even numbers */
				prime[j]=1;
			}
		}
	}
}
int main(){
	int a;
	sieve();
	while(scanf("%d",&a) != EOF){
		printf("%d\n",prime[a]); /*if 0,its prime*/
	}
	return 0;
}