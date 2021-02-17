#include<stdio.h>
int gcd(int,int);
int main(){
	int T,a,b,i,g;
	while(scanf("%d %d",&a,&b) != EOF){
		g=gcd(a,b);
		printf("%d\n",g);
	}
	return 0;
}

int gcd(int a,int b){
	if(b!=0) return gcd(b,a%b);
	return a;
}