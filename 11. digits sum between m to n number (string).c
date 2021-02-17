#include<stdio.h>
void add1(char []);
long long summation(char [],long long);
int main(){
	unsigned long long T,a,b,i,j,sum,n;
	char str[17];
	scanf("%llu",&T);
	while(T--){
		scanf("%llu %llu",&a,&b);
		n=(b-a)+1;
		for(j=0;j<16;j++) str[j]='0';
		str[16]='\0'; sum=0;
		for(j=15;a!=0;j--){
			str[j]=a%10+'0';
			sum+=str[j]-'0';
			a/=10;
		}
		for(i=1;i<n;i++){
			add1(str);
			sum=summation(str,sum);
		}
		printf("%s %lld\n",str,sum);
	}
	return 0;
}
void add1(char str[]){
	int c,temp,i=15;
	if(str[15]=='9'){
		c=1;str[15]='0';i--;
		while(c!=0){
			temp=str[i]-'0'+1;
			if(temp>9){
				str[i]='0'; c=1; i--;
			}
			else{
				str[i]=temp+'0';
				c=0;
			}
		}
	}
	else str[i]++;
}
long long summation(char str[], long long sum){
	int i;
	for(i=0;i<16;i++){
		sum+=str[i]-'0';
	}
	return sum;
}