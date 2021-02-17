#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);
int arr[100][100],s[100][100];
int i,j,k,l,n;

int max(int x,int y) { return x>y? x:y; }
void cumsum(){
	for(i=0;i<n;i++) for(j=0;j<n;j++){
		s[i][j]=arr[i][j];
		if(i>0) s[i][j]+=arr[i-1][j];
		if(j>0) s[i][j]+=arr[i][j-1];
		if(i>0 && j>0) s[i][j]-=arr[i-1][j-1];
	}
}
int maxsum(){
	int sub,submax=-127*100*100;
	for(i=0;i<n;i++) for(j=0;j<n;j++){
		for(k=i;k<n;k++) for(l=j;l<n;l++){
			sub=s[k][l];
			if(i>0) sub-=s[i-1][l];
			if(j>0) sub-=s[k][j-1];
			if(i>0 && j>0) sub+=s[i-1][j-1];
		}
		submax=max(submax,sub);	
}
	return submax;
}
int main(){
	while(scanf("%d",&n) != EOF){
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
		cumsum();
		printf("%d\n",maxsum());
	}
	return 0;
}