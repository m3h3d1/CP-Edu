#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int fibo(int n){
	if(n<=1) return n;
	return fibo(n-1)+fibo(n-2);
}
int main(){
	int T,a,n,i;
	printf("%d\n",fibo(8));
	return 0;
}