#include<stdio.h>
#include<math.h>
#define db(x) printf("%s is %d\n",#x,x);
int main(){
	int T,n,i;
	double res;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		res=0;
		for(i=1;i<=n;i++){
			res+=log10(i);
		}
		printf("%d\n",(int)res+1);
	}
	return 0;
}