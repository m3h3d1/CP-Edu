#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);
int main(){
	int T,x1,x2,b1,b2;
	char str[15];
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		sscanf(str,"%d",&x1); /*str as integer. x1 also integr. if str=265, x1=265*/
		sscanf(str,"%x",&x2); /*str as hexa. converted into integer(x2). if str=265 x2=613*/
		
		b1=0,b2=0;
		while(x1){
			b1+=x1&1, x1/=2;
		}
		while(x2){
			b2+=x2&1, x2/=2;
		}
		printf("%d %d\n",b1,b2);
	}
	return 0;
}