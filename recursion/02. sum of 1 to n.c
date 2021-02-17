#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int sum(int n){
	if(n==1) return 1;
	return n+sum(n-1);
}
int main(){
	int T,a,n,i;
	printf("%d\n",sum(10));
	return 0;
}