#include<stdio.h>
#include<math.h>
int main(){
	int T,i,n;
	double s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<2){
			printf("1\n");
			continue;
		}
		i=0,s=0;
		while(i<n){
			s+=log10(n-i);
			i++;
		}
		printf("%.lf\n",ceil(s));
	}
	return 0;
}