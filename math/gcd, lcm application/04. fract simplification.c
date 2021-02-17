#include<stdio.h>
int gcd(int,int);
int main(){
	int T,a,b,g;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a,&b);
		g=gcd(a,b);
		printf("%d\n", g);
		printf("%d/%d\n",a/g,b/g);
	}
	return 0;
}
int gcd(int a, int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}