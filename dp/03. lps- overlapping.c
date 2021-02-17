#include<stdio.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);

int max(int x,int y) { return x>y ? x:y; }
int lps(char str[],int i,int j){
    if(i==j) return 1;
    if(str[i]==str[j] && i+1==j) return 2;
    if(str[i]==str[j]) return lps(str,i+1,j-1)+2;
    return max(lps(str,i,j-1), lps(str,i+1,j));
}
int main(){
    char str[]="geeksforgeeks";
    int n=strlen(str);
    printf("The length of the lps is %d\n",lps(str,0,n-1));
    return 0;
}

/* geeksforgeeks: longest palindromic subsequence */