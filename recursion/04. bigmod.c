#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int bigmod(int b,int p,int m){
	if(p==1) return b%m;
	if(p%2==0){
		int x=bigmod(b,p/2,m);
		return (x*x)%m;
	}
	else return bigmod(b,p-1,m)%m * b%m; 
	/* (v%m * w%m)%m kora hocche na karon,
	return korar age ekbar mod kora hoyeche */
}
int main(){
	int T,a,n,i;
	printf("%d\n",bigmod(2,5,5));
	return 0;
}

/* a^b mod b */