#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char s1[100],s2[100];
    scanf("%s %s",s1,s2);
    while(s1[0]=='0'){
        for(i=0;s1[i]!='\0';i++){
            s1[i-1]=s1[i];
        }
        s2[i-1]='\0';
    }
    while(s2[0]=='0'){
        for(i=0;s2[i]!='\0';i++){
            s2[i-1]=s2[i];
        }
        s2[i-1]='\0';
    }
    if(strlen(s1)>strlen(s2)) printf("1st>2nd\n");
    else if(strlen(s2)>strlen(s1)) printf("2nd>1st\n");
    else if(strcmp(s1,s2)>0) printf("1st>2nd\n");
    else if(strcmp(s1,s2)<0) printf("2nd<1st\n");
    else printf("same\n");
    return 0;
}