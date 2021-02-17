#include<stdio.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);

void swap(char *x, char *y){
    char temp=*x;
    *x=*y;
    *y=temp;
}
void permute(char *a,int s,int e){ /*or, char a[]*/
    int i;
    if(s==e) printf("%s\n",a);
    else{
        for(i=s;i<=e;i++){
            swap((a+s),(a+i));
            permute(a,s+1,e);
            swap((a+s),(a+i));
        }
    }
}
int main(){
    int n;
    char str[]="abcd";
    n=strlen(str);
    permute(str,0,n-1);
    return 0;
}