#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int ncr(int n,int r){
	if(r==1) return n;
	if(n==r) return 1; /* or if(n==0 || n==r) return 1; */
	return ncr(n-1,r-1)+ncr(n-1,r);
}
int main(){
	int T,a,n,i;
	printf("%d\n",ncr(7,2));
	return 0;
}