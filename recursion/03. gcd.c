#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int gcd(int a, int b){
	if(b==0) return a; /* or, if(a%b==0) return b; */
	return gcd(b,a%b);
}
int main(){
	int T,a,n,i;
	printf("%d\n",gcd(4,18));
	return 0;
}