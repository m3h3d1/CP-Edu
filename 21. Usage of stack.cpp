#include<stdio.h>
#define SIZE 256
char stack[SIZE];
int top=-1;
void push(char ch){
    stack[++top]=ch;
}
void pop(){
    stack[top--]={'\0'};
}
int main(){
    int T,i;
    char ch;
    scanf("%d",&T); getchar();
    while(T--){
        stack[0]='\0';
        top=-1;
        int error=0;
        char *par=new char[SIZE+1];
        gets(par);
        for(i=0;par[i];i++){
            if(par[i]==' ') continue;
            if(par[i]=='[' || par[i]=='(') push(par[i]);
            else if(par[i]==']' && stack[top]=='[') pop();
            else if(par[i]==')' && stack[top]=='(') pop();
            else{
                error=1;
                break;
            }
        }
        if(error || top>-1) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}